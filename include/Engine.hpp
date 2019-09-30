// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"

namespace sub
{
    class Engine
    {
        Window m_mainWindow;

        public:

        inline Engine() {};
        inline ~Engine() { shutdown(); };

        void init();
        void run();
        void shutdown();
    };
}