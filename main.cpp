// SUBTRA entry point
// 2020 Matthias Scherba @szczm_

#include <iostream>

#include "SUBTRA.hpp"

using namespace SUBTRA;


int main (int, char**)
{
    Engine Engine;

    try
    {
        Engine.Initialize();
        Engine.Run();
    }
    catch (Exception& Exception)
    {
        Log::Error("Uncaught exception: ", Exception.what());
    }

    Engine.Shutdown();

    return 0;
}
