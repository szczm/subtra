// SUBTRA Engine class source
// 2020 Matthias Scherba @szczm_


#include "Engine.hpp"

#include <SDL2/SDL.h>

#include "Exception.hpp"
#include "Time.hpp"


SUBTRA::Engine::~Engine ()
{
    Shutdown();
}

void SUBTRA::Engine::Init ()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw SUBTRA::Exception {"Could not initialize SDL"};

    m_inputManager.Init();
    m_windowManager.Init();
}

void SUBTRA::Engine::Run ()
{
    while (m_isRunning)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
            ProcessEvent(event);

        Time::Update();

        m_windowManager.Update();
    }
}

void SUBTRA::Engine::Shutdown ()
{
    // m_windowManager.Shutdown();

    SDL_Quit();
}

void SUBTRA::Engine::ProcessEvent (SDL_Event a_event)
{
    m_inputManager.ProcessEvent(a_event);
    m_windowManager.ProcessEvent(a_event);

    if (a_event.type == SDL_QUIT)
        m_isRunning = false;
}