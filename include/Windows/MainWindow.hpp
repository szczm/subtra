// SUBTRA MainWindow class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include "GLCommon.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "Shader.hpp"
#include "Texture.hpp"


namespace SUBTRA
{
    // Move default main window properties away from construction site
    class MainWindow : public Window
    {
        public:

        MainWindow () = default;
        ~MainWindow () = default;

        void Open ();

        void UpdateIMGUI () override;
        void Render () override;

        void LoadTestData ();

        private:

        using Window::Open;

        Mesh m_testMesh {};
        Shader m_testShader {};
        Texture m_testTexture {};
        Object m_testObject {};
        glm::vec3 m_testAngles {};
        float m_testScale = 0.5f;
    };
}