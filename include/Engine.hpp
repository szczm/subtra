// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "InputManager.hpp"
#include "WindowManager.hpp"

namespace SUBTRA
{
    class Engine
    {
        public:

        Engine() = default;
        ~Engine();

        void init();
        void run();
        void shutdown();

        private:

        void processEvent(const SDL_Event& a_event);

        InputManager m_inputManager {};
        WindowManager m_windowManager {};

        bool m_running = true;
    };
}