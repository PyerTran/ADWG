#ifndef RADAR_MISSILE_HPP_
#define RADAR_MISSILE_HPP_

#include "radar.hpp"
namespace RADAR {
    class RADAR_MISSILE : public RADAR
    {
        public:
            std::vector<COORDS_t> run() override;
    
        private:
    
    };
}

#endif