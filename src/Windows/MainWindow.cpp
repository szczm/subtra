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


void SUBTRA::MainWindow::Open ()
{
    Open("SUBTRA", 800, 600);
    Maximize();
}

void SUBTRA::MainWindow::LoadTestData ()
{
    m_testMesh = Mesh {"assets/models/test.model"};
    m_testShader = Shader {"assets/shaders/test.vert", "assets/shaders/test.frag"};
    m_testTexture = Texture {"assets/textures/test.jpg"};

    m_testCamera = m_testObject.AddComponent<Camera>();
}

void SUBTRA::MainWindow::ProcessEvent(const SDL_Event& a_event)
{
    Window::ProcessEvent(a_event);

    if (a_event.type == SDL_WINDOWEVENT && a_event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        m_testCamera.get()->SetAspect(static_cast<float>(m_width) / static_cast<float>(m_height));
    }
}


void SUBTRA::MainWindow::UpdateIMGUI ()
{
    ImGui::Begin("Test Triangle", static_cast<bool *>(0), ImGuiWindowFlags_MenuBar);

    ImGui::LabelText("Time", "%f", Time::time);
    ImGui::LabelText("Delta time", "%f", Time::deltaTime);

    ImGui::DragFloat("Roll", &m_testAngles.x, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Pitch", &m_testAngles.y, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Yaw", &m_testAngles.z, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Scale", &m_testScale, 0.02f, -2.0f, 2.0f);
}

void SUBTRA::MainWindow::Render ()
{
    for (Component& component : ComponentManager::GetComponents())
    {
        component.Update();
    }

    for (Camera& camera : ComponentManager::GetComponents<Camera>())
    {
        camera.Update();
    }

    m_testObject.GetTransform().SetPosition(glm::vec3(1.0, 0.5, -3.0)).SetAngles(m_testAngles).SetScale(m_testScale);

    Clear();

    m_testShader.Use();
    m_testMesh.Bind();
    m_testTexture.Bind();

    // TODO: What So Not - >>>Better<<<
    m_testShader.Send("albedo", 0);
    m_testShader.Send("world", m_testObject.GetTransform().GetWorldMatrix());
    m_testShader.Send("view", glm::mat4(1.0));
    m_testShader.Send("projection", m_testCamera->GetProjectionMatrix());
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    Swap();
}