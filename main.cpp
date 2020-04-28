// SUBTRA entry point
// 2020 Matthias Scherba @szczm_

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
        Log::Error("Uncaught exception: ", ex.what());
    }

    engine.Shutdown();

    return 0;
}
