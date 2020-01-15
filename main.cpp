// SUBTRA entry point
// 2019 Matthias Scherba @szczm_

#include <iostream>

#include "SUBTRA.hpp"

using namespace SUBTRA;


int main (int, char**)
{
    Engine engine;

    try
    {
        engine.Init();
        engine.Run();
    }
    catch (Exception& ex)
    {
        // Printing is done by the exceptions themselves
    }

    engine.Shutdown();

    return 0;
}
