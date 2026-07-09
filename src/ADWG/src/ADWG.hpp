#ifndef ADWG_HPP_
#define ADWG_HPP_

#include <string>
#include "registry.hpp"
#include "vector2.hpp"

#include "IGraphicModule.hpp"

#include "Behaviours.hpp"
#include "attributes.hpp"
#include "Team.hpp"
#include "radar.hpp"
#include "datalink.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define ENTITY_MAX_COUNT 32
#define WINDOW_TITLE "Arcade"

namespace adwg
{
    enum GameStat {Blue_Win, Red_Win, Mutual, OnGoing, Pause, Menu};

    class GAME {
        public:
            int GameState;

            GAME(Vector2<int> dimension, IGraphicModule *GPI, registry *regis);
            ~GAME();
            void runMenu();
            void runGame();
            void runPause();

            void update_game();
        private:
            registry *game_inventory;
            IGraphicModule *_GPI;
    };
}

#endif