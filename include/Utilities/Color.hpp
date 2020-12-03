// SUBTRA Color class header
// 2020 Matthias Scherba @szczm_

#pragma once


namespace SUBTRA
{
    using byte = unsigned char;

    struct Color final
    {
        static Color FromByte (byte Red, byte Green, byte Blue, byte Alpha = 255);
        static Color FromLinear (float Red, float Green, float Blue, float Alpha = 1.0f);

        float Red = 1.0f;
        float Green = 0.0f;
        float Blue = 1.0f;
        float Alpha = 1.0f;
    };
}