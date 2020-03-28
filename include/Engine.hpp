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

        void Init ();
        void Run ();
        void Shutdown ();


        private:

        void ProcessEvent (SDL_Event a_event);

        InputManager m_inputManager {};
        WindowManager m_windowManager {};

        bool m_isRunning = true;
    };
}