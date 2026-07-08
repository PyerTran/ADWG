#include "sfml_specific.hpp"

namespace SFgraphics {
    
    SFEntityGraphics::SFEntityGraphics(sf::CircleShape *s) {
        this->shape = s;
    }

    SFEntityGraphics::~SFEntityGraphics() {
        free(shape);
    }

    // alawys a sf::circleshape
    void *SFEntityGraphics::get_graphics() {
        return this->shape;
    }
    
}