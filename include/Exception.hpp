// SUBTRA Exception class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <stdexcept>
#include <string>

namespace SUBTRA
{
    struct Exception : public std::runtime_error
    {
        Exception (const std::string& What);
        Exception (const char* What);
    };
}