// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_


#include "Engine.hpp"

#include <SDL2/SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"

SUBTRA::Engine::Engine() {}

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

    m_windowManager.init();
}

void SUBTRA::Engine::run()
{
    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);

            m_windowManager.processEvent(event);

            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            if (ImGui::GetIO().WantCaptureKeyboard == false)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }

            // if (ImGui::GetIO().WantCaptureMouse == false)
        }

        m_windowManager.update();
    }
}

void SUBTRA::Engine::shutdown()
{
    m_windowManager.shutdown();

	SDL_Quit();
}