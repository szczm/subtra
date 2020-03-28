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

void SUBTRA::MainWindow::ProcessEvent(SDL_Event a_event)
{
    Window::ProcessEvent(a_event);

    if (a_event.type == SDL_WINDOWEVENT && a_event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        m_testCamera.get()->SetAspect(static_cast<float>(m_width) / static_cast<float>(m_height));
    }
}


void SUBTRA::MainWindow::UpdateIMGUI ()
{
    ImGui::Begin("Test Triangle", static_cast<bool *>(nullptr), ImGuiWindowFlags_MenuBar);

    ImGui::LabelText("Time", "%f", Time::time);
    ImGui::LabelText("Delta time", "%f", Time::deltaTime);

    m_testColor.UpdateIMGUI();

    ImGui::DragFloat("Roll", &m_testAngles.x, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Pitch", &m_testAngles.y, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Yaw", &m_testAngles.z, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Scale", &m_testScale, 0.02f, -2.0f, 2.0f);

    for (Component& component : ComponentManager::GetComponents())
    {
        component.UpdateIMGUI();
    }
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

    m_testObject.transform.SetPosition(glm::vec3(1.0, 0.5, -3.0)).SetAngles(m_testAngles).SetScale(m_testScale);

    Clear();

    m_testShader.Use();
    m_testMesh.Bind();
    m_testTexture.Bind();

    // TODO: What So Not - >>>Better<<<
    m_testShader.Send("u_albedo", 0);
    m_testShader.Send("u_world", m_testObject.transform.GetWorldMatrix());
    m_testShader.Send("u_view", glm::mat4(1.0));
    m_testShader.Send("u_proj", m_testCamera->GetProjectionMatrix());
    m_testShader.Send("u_color", *m_testColor);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    Swap();
}