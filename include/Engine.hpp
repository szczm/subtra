// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "WindowManager.hpp"

namespace SUBTRA
{
    class Engine
    {
        public:

        Engine();
        ~Engine();

        void init();
        void run();
        void shutdown();


        private:

        WindowManager m_windowManager;
    };
}