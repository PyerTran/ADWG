#ifndef ADWG_HPP_
#define ADWG_HPP_

#include <string>
#include "registry.hpp"
#include "vector2.hpp"

#include "IGraphicModule.hpp"

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
            
            GAME(Vector2<int> dimension);
            ~GAME();
            void Menu();
            void rungame();
            void pause();

            void update_game();
        private:
            registry game_inventory;
            IGraphicModule *graphics;
    };
}

#endif