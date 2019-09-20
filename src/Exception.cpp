// SUBTRA Exception class source
// 2019 Matthias Scherba @szczm_

#include "Exception.hpp"

#include <stdexcept>

#include "Log.hpp"

sub::Exception::Exception(const char* a_what) : std::runtime_error(a_what)
{
    sub::Log::Error(a_what);
}