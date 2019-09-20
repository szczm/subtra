// SUBTRA entry point
// 2019 Matthias Scherba @szczm_

#include <iostream>

#include "SUBTRA.hpp"

using namespace sub;

int main(int argc, char* args[])
{
	Engine engine;

	try
	{
		engine.init();
		engine.run();
	}
	catch (Exception& ex)
	{
		// Printing has been taken care off by the exception
	}

	engine.shutdown();

	return 0;
}
