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

void AIRCRAFT::change_speed(int newspeed)
{
    if (newspeed == this->_speed) {
		return;
	}
    this->_changing_speed = (this->_fuel/2) + (this->_nb_missile/4);
    this->_step_speed = (newspeed - this->_speed)/this->_changing_speed;
}

void AIRCRAFT::update_alt()
{
    sparse_array<IBehaviours> &behaviours = regis->get_components<IBehaviours>();
    size_t id = behaviours.get_index(*this);
    sparse_array<flight_data_t> &blackboxes = regis->get_components<flight_data_t>();

    if (this->_changing_alt <= 0) {
        return;
    }
    this->_changing_alt -= 1;
    blackboxes[id]->position.z += this->_step_alt;
}

void AIRCRAFT::change_alt(int newalt)
{
    sparse_array<IBehaviours> &behaviours = regis->get_components<IBehaviours>();
    size_t id = behaviours.get_index(*this);
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
    sparse_array<IBehaviours> &behaviours = regis->get_components<IBehaviours>();
    size_t id = behaviours.get_index(*this);
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
    sparse_array<IBehaviours> &behaviours = regis->get_components<IBehaviours>();
    size_t id = behaviours.get_index(*this);
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

//AIRCRAFT DEF END


AWACS::AWACS()
{

};

void AWACS::update()
{
    
}


FIGHTER::FIGHTER(double fuel, int nb_missile, int def, int atk)
{
}