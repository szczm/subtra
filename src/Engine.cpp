// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_

#include "Engine.hpp"

#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "Exception.hpp"
#include "Log.hpp"

void sub::Engine::init()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

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

        glClearColor(1.0, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (auto window = m_mainWindow.getSDLWindow().lock())
        {
            SDL_GL_SwapWindow(window.get());
        }
    }
}

void sub::Engine::shutdown()
{
	SDL_Quit();
}