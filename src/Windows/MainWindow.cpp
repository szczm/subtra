// SUBTRA MainWindow class source
// 2019 Matthias Scherba @szczm_

#include "Windows/MainWindow.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Time.hpp"


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
}

void SUBTRA::MainWindow::UpdateIMGUI ()
{
    ImGui::Begin("Test Triangle", static_cast<bool *>(0), ImGuiWindowFlags_MenuBar);

    ImGui::LabelText("Time", "%f", Time::time);
    ImGui::LabelText("Delta time", "%f", Time::deltaTime);

    ImGui::DragFloat("Roll", &m_testAngles.x, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Pitch", &m_testAngles.y, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Yaw", &m_testAngles.z, 1.0f, -180.0f, 180.0f);
    ImGui::DragFloat("Scale", &m_testScale, 0.05f, -2.0f, 2.0f);
}

void SUBTRA::MainWindow::Render ()
{
    m_testObject.transform().setAngles(m_testAngles).setScale(m_testScale);

    Clear();

    m_testShader.Use();
    m_testMesh.Bind();
    m_testTexture.Bind();

    // TODO: What So Not - >>>Better<<<
    m_testShader.Send("testTexture", 0);
    m_testShader.Send("testMatrix", m_testObject.transform().getWorldMatrix());
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    Swap();
}