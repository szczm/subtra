// SUBTRA WindowManager class source
// 2019 Matthias Scherba @szczm_

#include "WindowManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"

SUBTRA::WindowManager::~WindowManager()
{
    shutdown();
}

void SUBTRA::WindowManager::init()
{
    initOpenGL();

	m_mainWindow.init("SUBTRA", 800, 600);
	m_mainWindow.maximize();

    initGLAD();
    initIMGUI();

    m_testMesh.init();
    m_testShader.init("data/shaders/test.vert", "data/shaders/test.frag");
}

void SUBTRA::WindowManager::shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void SUBTRA::WindowManager::processEvent(const SDL_Event& a_event)
{
    if (a_event.type == SDL_WINDOWEVENT && a_event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        m_mainWindow.resizeViewport(a_event.window.data1, a_event.window.data2);
    }
}

void SUBTRA::WindowManager::update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(m_mainWindow.getSDLWindow().get());

    ImGui::NewFrame();

    ImGui::ShowDemoWindow(static_cast<bool *>(0));
    ImGui::Render();

    m_mainWindow.clear();

    m_testShader.use();
    m_testMesh.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    m_mainWindow.swap();
}

void SUBTRA::WindowManager::initOpenGL()
{
    // Require OpenGL 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Misc. options
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
}

void SUBTRA::WindowManager::initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        throw SUBTRA::Exception("Could not initialize GLAD. Does your computer support OpenGL 3.3?");
    }
}

void SUBTRA::WindowManager::initIMGUI()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // antisocial energy saving club
    ImGui::StyleColorsDark();

    auto window = m_mainWindow.getSDLWindow().get();
    auto context = m_mainWindow.getContext().get();

    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}