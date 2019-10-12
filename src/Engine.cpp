// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_


#include "Engine.hpp"

#include <SDL2/SDL.h>

#include "Exception.hpp"

SUBTRA::Engine::~Engine()
{
    shutdown();
}

void SUBTRA::Engine::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        throw SUBTRA::Exception("Could not initialize SDL");
    }

    m_inputManager.init();
    m_windowManager.init();
}

void SUBTRA::Engine::run()
{
    while (m_running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            processEvent(event);
        }

        m_windowManager.update();
    }
}

void SUBTRA::Engine::shutdown()
{
    m_windowManager.shutdown();

	SDL_Quit();
}

void SUBTRA::Engine::processEvent(const SDL_Event& a_event)
{
    m_inputManager.processEvent(a_event);
    m_windowManager.processEvent(a_event);

    if (a_event.type == SDL_QUIT)
    {
        m_running = false;
    }
}