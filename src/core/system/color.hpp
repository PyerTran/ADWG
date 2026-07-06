#ifndef COLOR_HPP
#define COLOR_HPP

typedef unsigned char uint8;

namespace adwg {
    class Color {
    public:
        /**
         * @brief Construct a new Color object
         *
         * @param r red color [0-255]
         * @param g green color [0-255]
         * @param b blue color [0-255]
         * @param a transparency [0-255]
         */
        Color(uint8 r=255, uint8 g=255, uint8 b=255, uint8 a=255) : r(r), g(g), b(b),
                                                          a(a) {};

        /**
         * @brief Construct a new Color object
         *
         * @param color color object to clone
         */
        Color(const Color &color) : r(color.r), g(color.g), b(color.b),
                                    a(color.a) {};

        /**
         * @brief Destruct a Color object
         */
        ~Color() {};

        /**
         * @brief Get the Red object
         *
         * @return uint8 red color [0-255]
         */
        uint8 r;

        /**
         * @brief Get the Green object
         *
         * @return uint8 green color [0-255]
         */
        uint8 g;

        /**
         * @brief Get the Blue object
         *
         * @return uint8 blue color [0-255]
         */
        uint8 b;

        /**
         * @brief Get the Alpha object
         *
         * @return uint8 transparency [0-255]
         */
        uint8 a;

        static Color BLACK()        { return Color(0,   0,      0,      255); };
        static Color WHITE()        { return Color(255, 255,    255,    255); };
        static Color RED()          { return Color(255, 0,      0,      255); };
        static Color GREEN()        { return Color(0,   255,    0,      255); };
        static Color BLUE()         { return Color(0,   0,      255,    255); };
        static Color YELLOW()       { return Color(255, 255,    0,      255); };
        static Color MAGENTA()      { return Color(255, 0,      255,    255); };
        static Color CYAN()         { return Color(0,   255,    255,    255); };
        static Color GRAY()         { return Color(128, 128,    128,    255); };
        static Color DARK_GRAY()    { return Color(64,  64,     64,     255); };
        static Color LIGHT_GRAY()   { return Color(192, 192,    192,    255); };
        static Color DARK_BLUE()    { return Color(0,   0,      128,    255); };
        static Color DARK_GREEN()   { return Color(0,   128,    0,      255); };
        static Color DARK_RED()     { return Color(128, 0,      0,      255); };
        static Color DARK_YELLOW()  { return Color(128, 128,    0,      255); };
        static Color TRANSPARENT()  { return Color(0,   0,      0,      0); };
    };
}

#endif