#include "IBehaviours.hpp"
#include "Behaviours.hpp"
#include "datalink.hpp"
#include "radar.hpp"

AWACS::AWACS(Datalink *dl)
{
    if (!dl->ping_stack.empty()) {
        int size = dl->ping_stack.size();
        for (size_t i = 0; i < size; i += 1) {
            dl->ping_stack.pop();
        }
    }
    
};