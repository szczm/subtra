// SUBTRA Log class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <iostream>

#include "Exception.hpp"

namespace SUBTRA
{
    namespace Log
    {
        inline void Print(const char* a_what)
        {
            std::cout << "  " << a_what << std::endl;
        }

        inline void Debug(const char* a_what)
        {
            std::cerr << "? DEBUG: " << a_what << std::endl;
        }

        inline void Error(const char* a_what)
        {
            std::cerr << "! ERROR: " << a_what << std::endl;
        }

        inline void Error(SUBTRA::Exception& a_what)
        {
            std::cerr << "! ERROR: " << a_what.what() << std::endl;
        }

    }
}