#ifndef RADAR_HPP_
#define RADAR_HPP_

#include <vector>
#include <optional>

#include "attributes.hpp"
#include "registry.hpp"
#include "Team.hpp"


 class RADAR
{
    public:
        RADAR(double field_of_view, double range, int n_DL, registry *regis);        
        std::vector<flight_data_t> run();
    private:
        double range;
        double fov;
        int n_DL;
        flight_data_t *blackbox;
        registry *regis;
        std::vector<int> enemy_ids;
        std::vector<flight_data_t> detections;
        void IFF();
        
        
};

#endif