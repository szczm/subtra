// SUBTRA Exception class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <stdexcept>

namespace sub
{
    struct Exception : public std::runtime_error
    {
        explicit Exception(const char* a_what);
    };
}