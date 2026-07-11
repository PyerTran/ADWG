#include <vector>
#include "Team.hpp"
#include "radar.hpp"

class RWR {
    public:
        const std::vector<double> get_incidences();
        void RWR_clear();
    protected:
        friend RADAR;
        std::vector<double> _spike_incidences;
};