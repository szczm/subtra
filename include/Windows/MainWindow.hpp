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
#include "Utilities/Parameter.hpp"
#include "Utilities/Color.hpp"


namespace SUBTRA
{
    // Move default main window properties away from construction site
    class MainWindow final : public Window
    {
        public:

        // TODO: Implement move func. in case more data is added to class
        static MainWindow Open ();

        MainWindow();
        MainWindow(const MainWindow& a_other);
        MainWindow& operator= (MainWindow&& a_other);
        ~MainWindow();


        void LoadTestData ();

        void ProcessEvent (SDL_Event a_event) override;
        void UpdateIMGUI () override;
        void Render () override;


        private:

        // Hide the original method which allows additional parameters
        using Window::Open;
        MainWindow& operator= (const Window& a_other);


        // This is a mess, I know. I'll declutter it as I abstract things more
        Mesh m_testMesh {};
        Shader m_testShader {};
        Texture m_testTexture {};
        Object m_testObject {};
        glm::vec3 m_testAngles {};
        std::shared_ptr<Camera> m_testCamera {};
        float m_testScale = 0.5f;
        Parameter<Color> m_testColor {"Color"};
        // End mess
   };
}