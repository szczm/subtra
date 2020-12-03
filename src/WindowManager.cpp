// SUBTRA Window Manager class source
// 2020 Matthias Scherba @szczm_

#include "WindowManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"

#include "Log.hpp"

SUBTRA::WindowManager::~WindowManager ()
{
    Shutdown();
}

void SUBTRA::WindowManager::Initialize ()
{
    InitOpenGL();
    InitIMGUI();

    // InitGLAD();
    // InitIMGUI();

    MainWindow = MainWindow::Open();
    MainWindow.LoadTestData();
}

void SUBTRA::WindowManager::Shutdown ()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void SUBTRA::WindowManager::ProcessEvent (SDL_Event Event)
{
    MainWindow.ProcessEvent(Event);
}

void SUBTRA::WindowManager::Update ()
{
    // foreach Window:

    MainWindow.BeginIMGUI();

    MainWindow.UpdateIMGUI();
    MainWindow.Update();

    MainWindow.Clear();

    MainWindow.Render();
    MainWindow.DrawIMGUI();

    MainWindow.SwapBuffers();
}

void SUBTRA::WindowManager::InitOpenGL ()
{
    // Require OpenGL 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Misc. options
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    // Try enabling adaptive vsync
    if (SDL_GL_SetSwapInterval(-1) < 0)
    {
        // If failed, fallback to vsync
        SDL_GL_SetSwapInterval(1);
    }
}

void SUBTRA::WindowManager::InitIMGUI ()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // antisocial energy saving club
    ImGui::StyleColorsDark();
}