#include "MySfml.hpp"

namespace SFgraphics {
    void MySFML::init_window(int x, int y) {
        this->window = sf::RenderWindow(sf::VideoMode({x, y}), "ADWG");
    }
    void MySFML::clear_window() {
        this->window.clear();
    }
    void MySFML::close_window() {
        this->window.close();
    }
    void MySFML::refresh_window() {
        this->window.display();
    }

    void MySFML::draw_object(IEntityGraphics *eg, ObjectShape shape)
    {
        sf::CircleShape *s = (sf::CircleShape *)eg->get_graphics();
        this->window.draw(*s);
    }
    
}