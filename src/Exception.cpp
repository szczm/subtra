// SUBTRA Exception class source
// 2020 Matthias Scherba @szczm_

#include "Exception.hpp"

#include <stdexcept>

#include "Log.hpp"


SUBTRA::Exception::Exception (const char* a_what)
: std::runtime_error(a_what)
{

}