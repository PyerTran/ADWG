#ifndef ATTRIBUTES_HPP_
#define ATTRIBUTES_HPP_

// file for simple has-a components

#include "s_vector3.hpp"

typedef struct flight_data_s
{
    adwg::Vector3<double> position;
    // default always on 360° basis 
    double orientation; 
} flight_data_t;

enum CRAFT_TYPE {TYPE_AWACS, TYPE_FIGHTER, TYPE_MISSILE};
typedef struct craft_type_s
{
    CRAFT_TYPE type;
}craft_type_t;


//entities will be removed from the registry upon destruction, no need for this
typedef struct death_s
{

} death_t;

typedef struct shotdown_s
{

} shotdown_t;

#endif