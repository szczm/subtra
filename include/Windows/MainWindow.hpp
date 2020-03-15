// SUBTRA Main Window class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"

#include <memory>

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include "Components/Camera.hpp"
#include "GLCommon.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "Shader.hpp"
#include "Texture.hpp"


namespace SUBTRA
{
    // Move default main window properties away from construction site
    class MainWindow final : public Window
    {
        public:

        MainWindow () = default;
        ~MainWindow () = default;

        void Open ();
        void LoadTestData ();

        void ProcessEvent (const SDL_Event& a_event) override;
        void UpdateIMGUI () override;
        void Render () override;


        private:

        // Hide the original method which takes parameters
        using Window::Open;

        Mesh m_testMesh {};
        Shader m_testShader {};
        Texture m_testTexture {};
        Object m_testObject {};
        glm::vec3 m_testAngles {};
        std::shared_ptr<Camera> m_testCamera {};
        float m_testScale = 0.5f;
    };
}