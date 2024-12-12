#pragma once

namespace BrodyEngine
{
    struct Color
    {
        _Float16 r{0.f};
        _Float16 g{0.f};
        _Float16 b{0.f};
        _Float16 a{1.f};

        Color();
        Color(unsigned char color[])
        {
            r = color[0] / 255.f;
            g = color[1] / 255.f;
            b = color[2] / 255.f;
            a = color[3] / 255.f;
        }
        Color(float r, float g, float b)
            : r{r}, g{g}, b{b}, a{1.f} {}
        Color(float r, float g, float b, float a)
            : r{r}, g{g}, b{b}, a{a} {}
        Color(const Color& color)
            : r{color.r}, g{color.g}, b{color.b}, a{color.a} {}

        static const Color BLACK;
        static const Color WHITE;
        static const Color RED;
        static const Color BLUE;
        static const Color GREEN;
        static const Color YELLOW;
        static const Color MAGENTA;
        static const Color ORANGE;
        static const Color CYAN;
        static const Color GRAY;
        static const Color BROWN;

        static char* ToRayColor(Color color)
        {
            char* output = new char[4];
            output[0] = (char)(color.r * 255);
            output[1] = (char)(color.g * 255);
            output[2] = (char)(color.b * 255);
            output[3] = (char)(color.a * 255);
            return output;
        };
    };

    inline const Color Color::BLACK = Color(0.f, 0.f, 0.f);
    inline const Color WHITE = Color(1.f, 1.f, 1.f);
    inline const Color RED = Color(1.f, 0.f, 0.f);
    inline const Color BLUE = Color(0.f, 0.f, 1.f);
    inline const Color GREEN = Color(0.f, 1.f, 0.f);
    inline const Color YELLOW = Color(1.f, 1.f, 0.f);
    inline const Color MAGENTA = Color(1.f, 0.f, 1.f);
    inline const Color ORANGE = Color(1.f, 0.55f, 0.f);
    inline const Color CYAN = Color(0.f, 1.f, 1.f);
    inline const Color GRAY = Color(0.5f, 0.5f, 0.5f);
    inline const Color BROWN = Color(0.58f, 0.28f, 0.f);
}