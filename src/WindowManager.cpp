// SUBTRA Window Manager class source
// 2020 Matthias Scherba @szczm_

#include "WindowManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"


SUBTRA::WindowManager::~WindowManager ()
{
    Shutdown();
}

void SUBTRA::WindowManager::Init ()
{
    InitOpenGL();

    m_mainWindow.Open();

    InitGLAD();
    InitIMGUI();

    m_mainWindow.LoadTestData();
}

void SUBTRA::WindowManager::Shutdown ()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void SUBTRA::WindowManager::ProcessEvent (SDL_Event a_event)
{
    m_mainWindow.ProcessEvent(a_event);
}

void SUBTRA::WindowManager::Update ()
{
    ImGui_ImplOpenGL3_NewFrame();

    // TODO: allow multiple windows
    // TODO: improve below after decoupling context/window creation
    if (auto window = m_mainWindow.GetSDLWindow().lock())
    {
        ImGui_ImplSDL2_NewFrame(window.get());
    }
    
    ImGui::NewFrame();

    // ImGui::ShowDemoWindow(static_cast<bool *>(0));
    m_mainWindow.UpdateIMGUI();

    ImGui::End();
    ImGui::Render();

    m_mainWindow.Render();
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

void SUBTRA::WindowManager::InitGLAD ()
{
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
        throw SUBTRA::Exception {"Could not initialize GLAD. Does your computer support OpenGL 3.3?"};
}

void SUBTRA::WindowManager::InitIMGUI ()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // antisocial energy saving club
    ImGui::StyleColorsDark();

    // TODO: improve below after decoupling context/window creation
    if (auto window = m_mainWindow.GetSDLWindow().lock())
    if (auto context = m_mainWindow.GetContext().lock())
    {
        ImGui_ImplSDL2_InitForOpenGL(window.get(), context.get());
    }

    // TODO: wtf is this
    ImGui_ImplOpenGL3_Init("#version 330 core");
}