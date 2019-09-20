// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_

#include "Engine.hpp"

#include <SDL2/SDL.h>

#include "Exception.hpp"


void sub::Engine::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        throw sub::Exception("Could not initialize SDL");
    }

	m_mainWindow.init("SUBTRA", 800, 600);
	m_mainWindow.maximize();
}

void sub::Engine::run()
{
    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                running = false;
            }
        }
    }

}

void sub::Engine::shutdown()
{
	SDL_Quit();
}