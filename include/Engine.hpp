// SUBTRA Engine class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Mesh.hpp"
#include "Shader.hpp"
#include "Window.hpp"

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

        void initGLAD();
        void initSDL();
        void initOpenGL();
        void initIMGUI();

        Window m_mainWindow;
        Mesh m_testMesh;
        Shader m_testShader;
    };
}