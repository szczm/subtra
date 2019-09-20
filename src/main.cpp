// SUBTRA entry point
// 2019 Matthias Scherba @szczm_

#include <iostream>

#include "Engine.hpp"

using namespace sub;

int main(int argc, char* args[])
{
	Engine engine;

	try
	{
		engine.init();
		engine.run();
	}
	catch (const char* ex)
	{
		std::cerr << "CRITICAL ERR: " << ex << std::endl;
	}

	engine.shutdown();

	return 0;
}
