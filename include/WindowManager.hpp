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

        WindowManager() = default;
        ~WindowManager();

        void Init();
        void Shutdown();

        void ProcessEvent(const SDL_Event& a_event);
        void Update();

        private:

        void InitGLAD();
        void InitSDL();
        void InitOpenGL();
        void InitIMGUI();

        Window m_mainWindow {};
        Mesh m_testMesh {};
        Shader m_testShader {};
    };
}