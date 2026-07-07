#include <SFML/Graphics.hpp>
#include "MySfml.hpp"

namespace SFgraphics {

    //proto
    typedef struct EntityGraphics {
        sf::CircleShape *shape;
        ObjectShape s;
    } EG;


    // can only be a circleshape in SFML
    class SFEntityGraphics : public IEntityGraphics
    {
        public: 
            SFEntityGraphics(sf::CircleShape *s);
            ~SFEntityGraphics();
            void *get_graphics();
        private:
            sf::CircleShape *shape;
    };
}