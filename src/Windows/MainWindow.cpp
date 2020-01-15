// SUBTRA MainWindow class source
// 2019 Matthias Scherba @szczm_

#include "Windows/MainWindow.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"


void SUBTRA::MainWindow::Open()
{
    Open("SUBTRA", 800, 600);
    Maximize();
}

void SUBTRA::MainWindow::LoadTestData()
{
    m_testMesh = Mesh {"assets/models/test.model"};
    m_testShader = Shader {"assets/shaders/test.vert", "assets/shaders/test.frag"};
    m_testTexture = Texture {"assets/textures/test.jpg"};
}

void SUBTRA::MainWindow::UpdateIMGUI()
{
    ImGui::Begin("Test Triangle", static_cast<bool *>(0), ImGuiWindowFlags_MenuBar);

    ImGui::SliderFloat("Roll", &m_testAngles.x, -10.0f, 10.0f);
    ImGui::SliderFloat("Pitch", &m_testAngles.y, -10.0f, 10.0f);
    ImGui::SliderFloat("Yaw", &m_testAngles.z, -10.0f, 10.0f);
    ImGui::SliderFloat("Scale", &m_testScale, -10.0f, 10.0f);
}

void SUBTRA::MainWindow::Render()
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