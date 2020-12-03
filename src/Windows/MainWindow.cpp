// SUBTRA Main Window class source
// 2020 Matthias Scherba @szczm_

#include "Windows/MainWindow.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Components/Camera.hpp"
#include "ComponentManager.hpp"
#include "Time.hpp"

#include "Log.hpp"


// TODO: what is this, why is this, why isn't it static, what why
SUBTRA::MainWindow SUBTRA::MainWindow::Open ()
{
    MainWindow NewMainWindow;
    Window NewWindow = Window::Open("SUBTRA", 800, 600);    

    NewMainWindow.SDLContext = NewWindow.SDLContext;
    NewMainWindow.SDLWindow = NewWindow.SDLWindow;
    NewMainWindow.Maximize();

    return NewMainWindow;
}

void SUBTRA::MainWindow::LoadTestData ()
{
    TestMesh = Mesh::LoadFromFile("assets/models/test.model");
    TestShader = Shader::LoadFromFile("assets/shaders/test.vert", "assets/shaders/test.frag");
    TestTexture = Texture::LoadFromFile("assets/textures/test.jpg");

    TestCamera = TestObject.AddComponent<Camera>();
}

void SUBTRA::MainWindow::ProcessEvent(SDL_Event Event)
{
    Window::ProcessEvent(Event);

    if (Event.type == SDL_WINDOWEVENT && Event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        TestCamera.get()->SetAspectRatio(static_cast<float>(Width) / static_cast<float>(Height));
    }
}

void SUBTRA::MainWindow::UpdateIMGUI ()
{
    ImGui::Begin("Test Triangle", static_cast<bool *>(nullptr), ImGuiWindowFlags_MenuBar);

    ImGui::LabelText("Time", "%f", Time::TotalTime);
    ImGui::LabelText("Delta time", "%f ms", Time::DeltaTime * 1000.0f);

    TestColor.UpdateIMGUI();

    ImGui::DragFloat("Roll", &TestAngles.x, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Pitch", &TestAngles.y, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Yaw", &TestAngles.z, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Scale", &TestScale, 0.02f, -2.0f, 2.0f);

    for (Component& Component : ComponentManager::GetComponents())
    {
        Component.UpdateIMGUI();
    }
}

void SUBTRA::MainWindow::Render ()
{
    // TODO: extract update from render
    for (Component& Component : ComponentManager::GetComponents())
    {
        Component.Update();
    }

    // TODO: separate camera update? why?
    for (Camera& Camera : ComponentManager::GetComponents<Camera>())
    {
        Camera.Update();
    }

    TestObject.Transform.SetLocalPosition(glm::vec3(1.0, 0.5, -3.0)).SetLocalRotation(TestAngles).SetLocalScale(TestScale);

    Clear();

    TestShader.Use();
    TestMesh.Bind();
    TestTexture.Bind();

    // TODO: fix up this whole mess
    TestShader.Send("AlbedoTexture", 0);
    TestShader.Send("World", TestObject.Transform.GetWorldMatrix());
    TestShader.Send("View", glm::mat4(1.0));
    TestShader.Send("Projection", TestCamera->GetProjectionMatrix());
    TestShader.Send("Tint", TestColor.Value);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SwapBuffers();
}