#include "ADWG.hpp"
// every angle will repre

#define PLACEHOLDER_NB 8

namespace adwg
{
    GAME::GAME(Vector2<int> dimension, IGraphicModule *GPI, registry *regis) {
        this->game_inventory = regis;
        this->_GPI = GPI;
        this->_GPI->init_window(dimension.x, dimension.y);
        this->GameState = Menu;
    }

    void GAME::runGame()
    {
        sparse_array<IBehaviours> &behaviours = game_inventory->get_components<IBehaviours>();
        sparse_array<IEntityGraphics> &egs = game_inventory->get_components<IEntityGraphics>();
        sparse_array<Team> Teams = game_inventory->get_components<Team>();
        sparse_array<craft_type_t> types = game_inventory->get_components<craft_type_t>();

        // if done run game then there's no need for this portion
        std::vector<size_t> ids_overlord_red;
        std::vector<size_t> ids_overlord_blue;

        for (size_t i = 0; i < types.size(); i += 1) {
            if (types[i].has_value()) {
                if (types[i]->type == TYPE_AWACS) {
                    if (Teams[i].has_value()) {
                        if (Teams[i]->get_team() == RED) {
                            ids_overlord_red.push_back(i);
                        }
                        if (Teams[i]->get_team() == BLUE) {
                            ids_overlord_blue.push_back(i);
                        }
                    }
                }
            }
        }
        // end

        int red = 0;
        int blue = 0;

        while (this->GameState == OnGoing)
        {
            red = 0;
            blue = 0;

            for (size_t i = 0; i < behaviours.size(); i += 1) {
                if (behaviours[i].has_value())
                {
                    behaviours[i]->update();
                }
                if (egs[i].has_value())
                {
                    this->_GPI->draw_object(*egs[i]);
                }
                if (Teams[i].has_value())
                {
                    if (Teams[i]->get_team() == RED) {
                        red += 1;
                    }
                    if (Teams[i]->get_team() == BLUE) {
                        blue += 1;
                    }
                }
            }
            if (red == 0) {
                this->GameState = Blue_Win;
            }
            if (blue == 0) {
                this->GameState = Red_Win;
            }
            // win conditions
            // inputs
        }
    }

}