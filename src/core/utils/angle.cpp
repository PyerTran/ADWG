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

    adwg::Vector2<double> angle2coords(double angle)
    {
        adwg::Vector2<double> result;
        double angleRad = angle * (M_PI/180);
        double x = cos(angleRad);
        // as y increase going downwards
        double y = -sin(angleRad);
        
        result.x = x;
        result.y = y;
        return result;
    }
}