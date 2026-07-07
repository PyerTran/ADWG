#include "IBehaviours.hpp"
#include "Behaviours.hpp"
#include "datalink.hpp"
#include "radar.hpp"
#include "entity.hpp"

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
    if (newspeed == this->_speed) {
		return;
	}
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

void AIRCRAFT::change_alt(int newalt)
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    int coeff = 2;

    if (blackboxes[id]->position.z == newalt) {
        return;
    }
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
    // normalize to [0°, 360°] basis
    blackboxes[id]->orientation = Utils::Normalize(blackboxes[id]->orientation);
}

void AIRCRAFT::change_orientation(double neworientation)
{
    size_t id = Utils::get_self_id_from(*this, this->regis);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    double orientation_diff = 0;

    if (blackboxes[id]->orientation == neworientation) {
        return;
    }
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

    blackboxes[id]->position.x = (res_coords.x);
    blackboxes[id]->position.y = (res_coords.y);
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

    this->_status = ATTACK;
    double min_distance = WEZ;
    size_t closest_ping = 0;

    Radars[id]->IFF();
    std::vector<flight_data_t> detections = Radars[id]->run();
    for (size_t i = 0; detections.size(); i += 1) {
        double distance = detections[i].position.get_distance(blackboxes[id]->position);
        if (distance < min_distance) {
            // flee for your life from the closest ping
            this->_status = DEFEND;
            min_distance = distance;
            closest_ping = i;
        }
    }
    if (this->_status == DEFEND) {
        this->change_orientation(Utils::Normalize(detections[closest_ping].position.get_angle(blackboxes[id]->position)));
    }
}


FIGHTER::FIGHTER(registry **regis, double fuel, int nb_missile, int def, int atk)
{
}