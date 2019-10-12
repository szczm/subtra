// SUBTRA Log namespace header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <iostream>

#include "Exception.hpp"

namespace SUBTRA
{
    // I never really liked C++ streams. I wanted to have a print("a", 1, new Object) function
    // that is equivalent to std::cout << "a" << 1 << new Object << std::endl; (take note of the
    // implicit std::endl at the end), which is very easy to do with C++17 fold expressions! \o/
    namespace Log
    {
        template<typename ...Args>
        void Print(Args&&... args)
        {
            (std::cout << ... << args) << std::endl;
        }

        template<typename ...Args>
        void Error(Args&&... args)
        {
            std::cerr << "ERROR: ";
            (std::cerr << ... << args) << std::endl;
        }
    }
}