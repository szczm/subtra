// SUBTRA Log namespace header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <iostream>

#include "Exception.hpp"

namespace SUBTRA
{
    // I never really liked C++ streams. I wanted to have a print("a", 1, new Object) function
    // that is equivalent to "std::cout << "a" << 1 << new Object << std::endl", which is very
    // easy to do with C++17 fold expressions! \o/

    // TODO: you're not actually that smart you know. redo.
    namespace Log
    {
        template<typename ...Args>
        void Print (Args&&... args)
        {
            (std::cout << ... << args) << std::endl;
        }

        template<typename ...Args>
        void Error (Args&&... args)
        {
            std::cerr << "ERROR: ";
            (std::cerr << ... << args) << std::endl;
        }
    }
}