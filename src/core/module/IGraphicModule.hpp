#ifndef I_GRAPHIC_MODULE_HPP_
#define I_GRAPHIC_MODULE_HPP_

class IEntityGraphics {
    public:
        virtual void *get_graphics();
};

enum ObjectShape {CIRCLE, RECTANGLE, TRIANGLE};

class IGraphicModule {
    public:
        // window management
        virtual void init_window(int x, int y);
        virtual void refresh_window();
        virtual void clear_window();
        virtual void close_window();

        // object draw
        virtual void draw_object(IEntityGraphics g, ObjectShape s);

        // rotation
        virtual void set_rotation(IEntityGraphics g, double orientation);

        // debug_draw
        virtual void draw_radar_lines(int object_id);
};

#endif