// SUBTRA Color class header
// 2020 Matthias Scherba @szczm_

#pragma once


namespace SUBTRA
{
    using byte = unsigned char;

    struct Color final
    {
        // Helper function used to make class more readable at call site
        static Color FromByte (byte a_red, byte a_green, byte a_blue, byte a_alpha = 255);
        static Color FromLinear (float a_red, float a_green, float a_blue, float a_alpha = 1.0f);

        float red = 1.0f;
        float green = 0.0f;
        float blue = 1.0f;
        float alpha = 1.0f;
    };
}