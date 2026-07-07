#ifndef ANGLE_HPP_
#define ANGLE_HPP_


#include "vector2.hpp"
#include "s_vector3.hpp"

namespace Utils {

    // return 360° basis
    double Normalize(double a);

    // return a valued [-180°, 180°]
    double DeNormalize(double a);

    // from angle get 2d heading
    adwg::Vector2<double> angle2coords(double angle);
}

#endif