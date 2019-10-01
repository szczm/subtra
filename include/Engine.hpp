// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Mesh.hpp"
#include "Shader.hpp"
#include "Window.hpp"

namespace sub
{
    class Engine
    {
        public:

        inline Engine() {};
        inline ~Engine() { shutdown(); };

        void init();
        void run();
        void shutdown();


        private:

        void initOpenGL();
        void initSDL();

        Window m_mainWindow;
        Mesh m_testMesh;
        Shader m_testShader;
    };
}