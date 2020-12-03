// SUBTRA Color class source
// 2020 Matthias Scherba @szczm_

#include "Utilities/Color.hpp"


SUBTRA::Color SUBTRA::Color::FromByte (byte Red, byte Green, byte Blue, byte Alpha)
{
    Color NewColor;

    NewColor.Red = Red / 256.0f;
    NewColor.Green = Green / 256.0f;
    NewColor.Blue = Blue / 256.0f;
    NewColor.Alpha = Alpha / 256.0f;

    return NewColor;
}

SUBTRA::Color SUBTRA::Color::FromLinear (float Red, float Green, float Blue, float Alpha)
{
    Color NewColor;

    NewColor.Red = Red;
    NewColor.Green = Green;
    NewColor.Blue = Blue;
    NewColor.Alpha = Alpha;

    return NewColor;
}