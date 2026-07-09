#ifndef DATALINK_HPP_
#define DATALINK_HPP_

#include <queue>
#include "attributes.hpp"
#include "Behaviours.hpp"

class Datalink {
    public:
        std::vector<flight_data_t> get_datalink();

    private:
        friend AWACS;
        std::vector<flight_data_t> pings;
};

#endif