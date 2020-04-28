// SUBTRA Exception class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <stdexcept>

namespace SUBTRA
{
    // Subclassed exception in case I decide to add anything to it
    struct Exception : public std::runtime_error
    {
        explicit Exception (const char* a_what);
    };
}