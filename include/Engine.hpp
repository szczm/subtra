// SUBTRA Engine class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "InputManager.hpp"
#include "WindowManager.hpp"

namespace SUBTRA
{
    class Engine final
    {

    public:

        Engine () = default;
        ~Engine ();

        void Initialize ();
        void Run ();
        void Shutdown ();


    private:

        void ProcessEvent (SDL_Event Event);

        SUBTRA::InputManager InputManager {};
        SUBTRA::WindowManager WindowManager {};

        bool IsRunning = true;
    };
}