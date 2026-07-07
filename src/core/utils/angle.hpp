#ifndef ANGLE_HPP_
#define ANGLE_HPP_

namespace Utils {

    // return 360° basis
    double Normalize(double a);
    
    // return a valued [-180°, 180°]
    double DeNormalize(double a);

}

#endif