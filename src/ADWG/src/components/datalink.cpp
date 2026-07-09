#include "datalink.hpp"

std::vector<flight_data_t> Datalink::get_datalink()
{
    return this->pings;
}
