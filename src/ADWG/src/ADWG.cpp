#include "ADWG.hpp"
// every angle will repre

#define PLACEHOLDER_NB 8

namespace adwg
{
    GAME::GAME(Vector2<int> dimension) {
        this->graphics->init_window(dimension.x, dimension.y);
        this->GameState = OnGoing;
    }

}