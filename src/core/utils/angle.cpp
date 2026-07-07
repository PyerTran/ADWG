#include "angle.hpp"

namespace Utils {

    // return 360° basis
    double Normalize(double a)
    {
        while (a < 0) a += 360;
        while (a >= 360) a -= 360;
        return a;
    }
    
    // return a valued [-180°, 180°]
    double DeNormalize(double a)
    {
        while (a > 180) a -= 360;
        return a;
    }
}