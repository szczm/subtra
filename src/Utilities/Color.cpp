// SUBTRA Color class source
// 2020 Matthias Scherba @szczm_

#include "Utilities/Color.hpp"


SUBTRA::Color SUBTRA::Color::FromByte (byte a_red, byte a_green, byte a_blue, byte a_alpha)
{
    Color color;

    color.red = a_red / 256.0f;
    color.green = a_green / 256.0f;
    color.blue = a_blue / 256.0f;
    color.alpha = a_alpha / 256.0f;

    return color;
}

SUBTRA::Color SUBTRA::Color::FromLinear (float a_red, float a_green, float a_blue, float a_alpha)
{
    Color color;

    color.red = a_red;
    color.green = a_green;
    color.blue = a_blue;
    color.alpha = a_alpha;

    return color;
}