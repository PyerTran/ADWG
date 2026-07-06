#ifndef RADAR_AWACS_HPP_
#define RADAR_AWACS_HPP_

#include "radar.hpp"

namespace RADAR {
    class RADAR_AWACS : public RADAR
    {
        public:
            std::vector<COORDS_t> run() override;
        
        private:
            void transmit_datalink(std::vector<COORDS_t> detections);
    };
}

#endif