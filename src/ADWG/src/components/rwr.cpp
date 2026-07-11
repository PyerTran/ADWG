#include "rwr.hpp"

void RWR::RWR_clear() {
    this->_spike_incidences.clear();
}

const std::vector<double> RWR::get_incidences()
{
    return this->_spike_incidences;
}
    