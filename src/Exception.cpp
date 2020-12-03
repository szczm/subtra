// SUBTRA Exception class source
// 2020 Matthias Scherba @szczm_

#include "Exception.hpp"

#include "Log.hpp"


SUBTRA::Exception::Exception (const std::string& What)
: std::runtime_error(What)
{

}
SUBTRA::Exception::Exception (const char* What)
: std::runtime_error(What)
{

}