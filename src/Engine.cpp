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

void SUBTRA::Engine::Initialize ()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw SUBTRA::Exception {"Could not initialize SDL"};

    InputManager.Initialize();
    WindowManager.Initialize();
}

void SUBTRA::Engine::Run ()
{
    while (IsRunning)
    {
        SDL_Event Event;

        while (SDL_PollEvent(&Event))
            ProcessEvent(Event);

        Time::Update();

        WindowManager.Update();
    }
}

void SUBTRA::Engine::Shutdown ()
{
    // WindowManager.Shutdown();

    SDL_Quit();
}

void SUBTRA::Engine::ProcessEvent (SDL_Event Event)
{
    InputManager.ProcessEvent(Event);
    WindowManager.ProcessEvent(Event);

    if (Event.type == SDL_QUIT)
        IsRunning = false;
}