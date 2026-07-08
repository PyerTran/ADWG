#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "IGraphicModule.hpp"


namespace SFgraphics 
{
    class MySFML : public IGraphicModule 
    {
        public:
            MySFML();
            ~MySFML();

            void init_window(int x, int y);
            void refresh_window();
            void clear_window();
            void close_window();

            void draw_object(IEntityGraphics *eg, ObjectShape s); //everything is a circle shape lmao
            
            // orientation is on 360° basis
            void set_rotation(IEntityGraphics *eg, double orientation);
            void draw_radar_lines(int object_id);

        private:
            sf::RenderWindow window;
            
    };
}