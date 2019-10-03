// SUBTRA WindowManager class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include "GLCommon.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Window.hpp"

namespace SUBTRA
{
    class WindowManager
    {
        public:

        WindowManager();
        ~WindowManager();

        void init();
        void shutdown();

        void processEvent(const SDL_Event& a_event);
        void update();


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