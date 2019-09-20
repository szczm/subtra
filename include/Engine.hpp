// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#include "Window.hpp"

namespace sub
{
    class Engine
    {
        Window m_mainWindow;

        public:

        Engine() {};
        ~Engine() {};

        void init();
        void run();
        void shutdown();
    };
}