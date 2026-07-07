#ifndef DATALINK_HPP_
#define DATALINK_HPP_

#include <queue>
#include "attributes.hpp"
#include "Behaviours.hpp"

class Datalink {
    public:
        flight_data_t* get_datalink();
        std::queue<flight_data_t> *get_datalink_stack();

    private:
        friend AWACS;
        flight_data_t ping_list[6];
        std::queue<flight_data_t> ping_stack;

};

#endif