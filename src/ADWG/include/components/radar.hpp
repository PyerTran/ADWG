#ifndef RADAR_HPP_
#define RADAR_HPP_

#include <vector>

#include "coordinates.hpp"

 class RADAR
{
    public:
        RADAR(double field_of_view, double range, int n_DL)
        {
            this->fov = field_of_view;
            this->range=range;
            this->n_DL=n_DL;
        }
        
        virtual std::vector<COORDS_t> run();
    private:
        double range;
        double fov;
        int n_DL;
        float *orientation;
        
};

#endif