// SUBTRA Exception class source
// 2019 Matthias Scherba @szczm_

#include "Exception.hpp"

#include <stdexcept>

#include "Log.hpp"

SUBTRA::Exception::Exception(const char* a_what) : std::runtime_error(a_what)
{
    SUBTRA::Log::Error(a_what);
}