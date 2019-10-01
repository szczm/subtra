// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_

#include <glad/glad.h>

#include "Engine.hpp"

#include <SDL2/SDL.h>
#include <vector>
#include "GLCommon.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Exception.hpp"
#include "Log.hpp"

void SUBTRA::Engine::init()
{
    // Init... stuff
    initSDL();
    initOpenGL();

    // Create main window and optimize it
	m_mainWindow.init("SUBTRA", 800, 600);
	m_mainWindow.maximize();

    // GLAD requires a current context
    initGLAD();
    initIMGUI();

    m_testMesh.init();

    m_testShader.init("a", "b", "c");

    // std::cout << glGetString(GL_VERSION) << std::endl;
}

void SUBTRA::Engine::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        throw SUBTRA::Exception("Could not initialize SDL");
    }
}

void SUBTRA::Engine::initOpenGL()
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

void SUBTRA::Engine::initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        throw SUBTRA::Exception("Could not initialize GLAD");
    }
}

void SUBTRA::Engine::initIMGUI()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // antisocial energy saving club
    ImGui::StyleColorsDark();

    // TODO: Rewrite? Too smart-y
    {
        auto window = m_mainWindow.getSDLWindow().lock();
        auto context = m_mainWindow.getContext().lock();

        if (window && context)
        {
            ImGui_ImplSDL2_InitForOpenGL(window.get(), context.get());
        }
    }

    ImGui_ImplOpenGL3_Init("#version 330 core");
}

void SUBTRA::Engine::run()
{
    bool running = true;
    bool show_demo = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);

            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            if (ImGui::GetIO().WantCaptureKeyboard == false)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }

            // if (ImGui::GetIO().WantCaptureMouse == false)

			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				m_mainWindow.resizeViewport(event.window.data1, event.window.data2);
			}
        }


        ImGui_ImplOpenGL3_NewFrame();

        if (auto window = m_mainWindow.getSDLWindow().lock())
        {
            ImGui_ImplSDL2_NewFrame(window.get());
        }

        ImGui::NewFrame();

        ImGui::ShowDemoWindow(&show_demo);

        ImGui::Render();

        m_mainWindow.clear();

        m_testShader.use();
        m_testMesh.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        m_mainWindow.swap();
    }
}

void SUBTRA::Engine::shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

	SDL_Quit();
}