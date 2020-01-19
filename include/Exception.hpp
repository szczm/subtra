// SUBTRA Exception class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <stdexcept>

namespace SUBTRA
{
    struct Exception : public std::runtime_error
    {
        explicit Exception (const char* a_what);
    };
}