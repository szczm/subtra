// SUBTRA WindowManager class source
// 2019 Matthias Scherba @szczm_

#include "WindowManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"


SUBTRA::WindowManager::~WindowManager()
{
    Shutdown();
}

void SUBTRA::WindowManager::Init()
{
    InitOpenGL();
    
	m_mainWindow.Open();

    InitGLAD();
    InitIMGUI();

    m_testMesh = Mesh {"assets/models/test.model"};
    m_testShader = Shader {"assets/shaders/test.vert", "assets/shaders/test.frag"};

    m_testTexture = Texture {"assets/textures/wall.jpg"};
}

void SUBTRA::WindowManager::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void SUBTRA::WindowManager::ProcessEvent(const SDL_Event& a_event)
{
    if (a_event.type == SDL_WINDOWEVENT && a_event.window.event == SDL_WINDOWEVENT_RESIZED)
        m_mainWindow.ResizeViewport(a_event.window.data1, a_event.window.data2);
}

void SUBTRA::WindowManager::Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_mainWindow.GetSDLWindow().get());

    ImGui::NewFrame();

    ImGui::ShowDemoWindow(static_cast<bool *>(0));
    ImGui::Render();

    m_mainWindow.Clear();

    m_testShader.Use();
    m_testMesh.Bind();
    m_testTexture.Bind();

    // TODO: What So Not - >>>Better<<<
    m_testShader.Send("testTexture", 0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    m_mainWindow.Swap();
}

void SUBTRA::WindowManager::InitOpenGL()
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

void SUBTRA::WindowManager::InitGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
        throw SUBTRA::Exception {"Could not initialize GLAD. Does your computer support OpenGL 3.3?"};
}

void SUBTRA::WindowManager::InitIMGUI()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // antisocial energy saving club
    ImGui::StyleColorsDark();

    auto window = m_mainWindow.GetSDLWindow().get();
    auto context = m_mainWindow.GetContext().get();

    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}