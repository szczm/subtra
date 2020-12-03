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

        static MainWindow Open ();

        MainWindow () = default;
        MainWindow& operator= (MainWindow&&);
        MainWindow (MainWindow&&);
        MainWindow (MainWindow&) = delete;

        MainWindow& operator= (Window&&);

        void LoadTestData ();

        void ProcessEvent (SDL_Event Event) override;
        void UpdateIMGUI () override;
        void Update () override;
        void Render () override;


    private:

        Mesh TestMesh {};
        Shader TestShader {};
        Texture TestTexture {};
        Object TestObject {};
        glm::vec3 TestAngles {};
        std::shared_ptr<Camera> TestCamera {};
        float TestScale = 0.5f;
        Parameter<Color> TestColor {"Color"};
   };
}