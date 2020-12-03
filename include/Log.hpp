// SUBTRA Log namespace header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <iostream>


namespace SUBTRA
{
    // Simple "logs what you throw at it" Log functions using C++17 fold expressions.
    // Usage example:
    //     Log::Error("Could not open vertex shader file: ", PathToVertexShaderFile);
    namespace Log
    {
        template<typename ...Args>
        void Print (Args&&... Arguments)
        {
            (std::cout << ... << Arguments) << std::endl;
        }

        template<typename ...Args>
        void Error (Args&&... Arguments)
        {
            std::cerr << "ERROR: ";
            (std::cerr << ... << Arguments) << std::endl;
        }
    }
}