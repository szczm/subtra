// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_

#include "Engine.hpp"

#include <SDL2/SDL.h>

#include "Exception.hpp"
#include "Log.hpp"

void sub::Engine::init()
{
    // Init... stuff
    initOpenGL();
    initSDL();

    // Create main window and optimize it
	m_mainWindow.init("SUBTRA", 800, 600);
	m_mainWindow.maximize();
}

void sub::Engine::initOpenGL()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}

void sub::Engine::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        throw sub::Exception("Could not initialize SDL");
    }
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

        m_mainWindow.clear();
        m_mainWindow.swap();
    }
}

void sub::Engine::shutdown()
{
	SDL_Quit();
}