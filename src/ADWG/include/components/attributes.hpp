#ifndef ATTRIBUTES_HPP_
#define ATTRIBUTES_HPP_

#include "s_vector3.hpp"

typedef struct flight_data_s
{
    adwg::Vector3<int> position;
    // default always on 360° basis 
    double orientation; 
} flight_data_t;

typedef struct shotdown_s
{

} shotdown_t;

#endif