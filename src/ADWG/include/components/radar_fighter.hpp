#ifndef RADAR_FIGHTER_HPP_
#define RADAR_FIGHTER_HPP_

#include "radar.hpp"
namespace RADAR {
    class RADAR_FIGHTER : public RADAR
    {
        public:
            std::vector<COORDS_t> run() override;
    };
}

#endif