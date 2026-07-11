#include "IBehaviours.hpp"
#include "Behaviours.hpp"
#include "datalink.hpp"
#include "radar.hpp"
#include "entity.hpp"
#include <algorithm>

// AIRCRAFT DEF

void AIRCRAFT::update_speed()
{
    if (this->_changing_speed <= 0) {
        return;
    }
    this->_changing_speed -= 1;
    this->_speed += this->_step_speed;
}

void AIRCRAFT::change_speed(double newspeed)
{
    if (newspeed == this->_speed || newspeed == this->_newspeed) {
		return;
	}
    this->_newspeed = newspeed;
    this->_changing_speed = (this->_fuel/2) + (this->_nb_missile/4);
    this->_step_speed = (newspeed - this->_speed)/ (double)this->_changing_speed;
}

void AIRCRAFT::update_alt()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    if (this->_changing_alt <= 0) {
        return;
    }
    this->_changing_alt -= 1;
    blackboxes[id]->position.z += this->_step_alt;
}

void AIRCRAFT::change_alt(double newalt)
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    int coeff = 2;

    if (blackboxes[id]->position.z == newalt || newalt == this->_newalt) {
        return;
    }
    this->_newalt = newalt;
    if (blackboxes[id]->position.z > newalt) {
        this->_changing_alt = ((this->_fuel/2) + (this->_nb_missile/4))/coeff;
    } else {
        this->_changing_alt = ((this->_fuel/2) + (this->_nb_missile/4));
    }
    this->_step_alt = (newalt - blackboxes[id]->position.z) / this->_changing_alt;
}

void AIRCRAFT::update_orientation()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    if (this->_changing_orientation <= 0) {
        return;
    }
    this->_changing_orientation -= 1;
    blackboxes[id]->orientation += this->_step_orientation;
    // normalize to [0°, 360°[ basis
    blackboxes[id]->orientation = Utils::Normalize(blackboxes[id]->orientation);
}

void AIRCRAFT::change_orientation(double neworientation)
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    double orientation_diff = 0;

    if (blackboxes[id]->orientation == neworientation || neworientation == this->_neworientation) {
        return;
    }
    this->_neworientation = neworientation;
    orientation_diff = neworientation - blackboxes[id]->orientation;
    if (abs(orientation_diff) > 15) {
        this->_changing_orientation = ((this->_fuel/2) + (this->_nb_missile/4));
    } else {
        this->_changing_orientation = 2;
    }
    this->_step_orientation = orientation_diff / this->_changing_orientation;
}

void AIRCRAFT::move()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();
    adwg::Vector2<double> coords_heading;
    adwg::Vector2<double> res_coords;

    this->update_speed();
    this->update_orientation();
    this->update_alt();

    // how to pass orientation (360°) * distance to 2d coords
    coords_heading = Utils::angle2coords(blackboxes[id]->orientation);
    res_coords = coords_heading * (double)this->_speed;

    blackboxes[id]->position.x += (res_coords.x);
    blackboxes[id]->position.y += (res_coords.y);
}

void AIRCRAFT::plot_course(adwg::Vector3<double> coords, double speed)
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> blackboxes = regis->get_components<flight_data_t>();
    
    adwg::Vector3<double> selfpos = blackboxes[id]->position;
    // between -180° and 180°
    double absolute_angle = selfpos.get_angle(coords);
    this->change_orientation(Utils::Normalize(absolute_angle));
    this->change_speed(speed);
}

//AIRCRAFT DEF END


AWACS::AWACS(registry **regis)
{
    this->regis = *regis;
    this->_atk = 0;
    this->_def = 0;
    this->_nb_missile = 0;
    this->_fuel = 183; // as per 747 - 100 available numbers
};

/**
 * @brief AWACS behaviour follows 3 priority in order
 * 1: survive
 * 2: provide datalink to its team mates
 * 3: Loiter in the map
 * 
 * To survive the AWACS will always flee that means if pinged or targeted
 * it will turn away
 * To provide vision for its team mates awacs will move "Team forward" 
 * and try to stay at a fair distance of 3 of its closest team mates
 * if it cannot push up and but shouldn't flee (because it would go out of the map
 * / leave its team mate behind) it will loiter around going to right and left of the map
 * 
 * further more AWACS speed is limit to 800px per min (~0.223 every 1/60th of second)
 */
void AWACS::update()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<RADAR> &Radars = regis->get_components<RADAR>();
    sparse_array<flight_data_t> blackboxes = regis->get_components<flight_data_t>();
    sparse_array<Datalink> &datalinking = regis->get_components<Datalink>();

    double prescribe_speed = AWACS_TOPSPEED;
    adwg::Vector3<double> push_point;
    this->_status = ATTACK;
    Radars[id]->IFF();
    std::vector<flight_data_t> detections = Radars[id]->run();

    // sort detection as the closest to farthest
    std::sort(detections.begin(), detections.end(), [this](const flight_data_t &a, flight_data_t &b){
        size_t id = Utils::get_self_id_from(*this, this->regis);
        sparse_array<flight_data_t> blackboxes = regis->get_components<flight_data_t>();

        double dist_a = blackboxes[id]->position.get_distance(a.position);
        double dist_b = blackboxes[id]->position.get_distance(b.position);

        return dist_a < dist_b;
    });
    // Datalink to your team (the shares a single instance of Datalink, sets for one, sets for all)
    datalinking[id]->pings = std::vector<flight_data_t>(detections);
    if (detections[0].position.get_distance(blackboxes[id]->position) < WEZ) {
        this->_status = DEFEND;
    }
    /*
    if (this->_status == DEFEND) {
        this->change_orientation(Utils::Normalize(detections[0].position.get_angle(blackboxes[id]->position)));
        this->change_speed(AWACS_TOPSPEED);
    }*/
    switch (this->_status)
    {
    case DEFEND:
        /* code */
        this->change_orientation(Utils::Normalize(detections[0].position.get_angle(blackboxes[id]->position)));
        this->change_speed(AWACS_TOPSPEED);
        break;
    case ATTACK:
        push_point = this->where_to_push();
        if (push_point.get_distance(blackboxes[id]->position) < WEZ_WARNING) {
            prescribe_speed /= 2;
        }
        this->plot_course(push_point, prescribe_speed);
        break;
    default:
        
        break;
    }
}

std::vector<flight_data_t> AWACS::find_my_allies()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<Team> teams = this->regis->get_components<Team>();
    sparse_array<flight_data_t> blackboxes = this->regis->get_components<flight_data_t>();
    std::vector<flight_data_t> allies;

    Team myteam = teams[id].value();

    for (size_t i = 0; i < blackboxes.size(); i += 1) {
        if (blackboxes[i].has_value() &&
        (teams[i].has_value() &&
        teams[i].value().get_team() == myteam.get_team())) {
            allies.push_back(*blackboxes[i]);
        }
    }
    std::sort(allies.begin(), allies.end(), [this](const flight_data_t &a, flight_data_t &b){
        size_t id = Utils::get_self_id_from(*this, this->regis);
        sparse_array<flight_data_t> blackboxes = regis->get_components<flight_data_t>();

        double dist_a = blackboxes[id]->position.get_distance(a.position);
        double dist_b = blackboxes[id]->position.get_distance(b.position);

        return dist_a < dist_b;
    });
    return allies;
}

adwg::Vector3<double> AWACS::where_to_push()
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = this->regis->get_components<flight_data_t>();
    adwg::Vector3<double> coords;

    std::vector<flight_data_t> allies = this->find_my_allies();
    size_t n = 1;
    for (n = 1; n <= 3 && n <= allies.size(); n += 1)
    {
        coords += allies[n - 1].position;   
    }
    coords = coords / (double)n;

    return coords;
}

FIGHTER::FIGHTER(registry **regis, double fuel, int nb_missile, int def, int atk)
{
}