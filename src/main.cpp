// SUBTRA entry point
// 2019 Matthias Scherba @szczm_

#include <iostream>

#include "SUBTRA.hpp"

using namespace sub;

int main(int, char**)
{
	Engine engine;

	try
	{
		engine.init();
		engine.run();
	}
	catch (Exception& ex)
	{
		// Printing is done by the exceptions themselves
	}

	engine.shutdown();

	return 0;
}
