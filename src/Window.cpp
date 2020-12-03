// SUBTRA Window class source
// 2020 Matthias Scherba @szczm_

#include "Window.hpp"

#include "Exception.hpp"
#include "Log.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"


SUBTRA::Window SUBTRA::Window::Open (const std::string& Title, uint Width, uint Height)
{
    Window NewWindow;

    // Create window
    NewWindow.SDLWindow = SDL_CreateWindow(
        Title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Width, Height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );

    if (NewWindow.SDLWindow == nullptr)
    {
        throw SUBTRA::Exception("Could not open window");
    }

    // ...and create context
    NewWindow.SDLContext = SDL_GL_CreateContext(NewWindow.SDLWindow);

    if (NewWindow.SDLContext == nullptr)
    {
        throw SUBTRA::Exception("Could not open context");
    }

    SDL_GL_MakeCurrent(NewWindow.SDLWindow, NewWindow.SDLContext);

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        throw SUBTRA::Exception("Could not initialize GLAD. Does your computer support OpenGL 3.3?");
    }
    
    ImGui_ImplSDL2_InitForOpenGL(NewWindow.SDLWindow, NewWindow.SDLContext);

    // TODO: the hell is this
    ImGui_ImplOpenGL3_Init("#version 330 core");

    NewWindow.Width = Width;
    NewWindow.Height = Height;

    return NewWindow;
}

SUBTRA::Window::Window (SUBTRA::Window&& Victim)
{
    SDLWindow = Victim.SDLWindow;
    SDLContext = Victim.SDLContext;
    Width = Victim.Width;
    Height = Victim.Height;

    Victim.SDLWindow = nullptr;
    Victim.SDLContext = nullptr;
}

SUBTRA::Window& SUBTRA::Window::operator= (SUBTRA::Window&& Victim)
{
    SDLWindow = Victim.SDLWindow;
    SDLContext = Victim.SDLContext;
    Width = Victim.Width;
    Height = Victim.Height;

    Victim.SDLWindow = nullptr;
    Victim.SDLContext = nullptr;

    return *this;
}

SUBTRA::Window::~Window ()
{   
    SDL_DestroyWindow(SDLWindow);
    SDL_GL_DeleteContext(SDLContext);

    SDLWindow = nullptr;
    SDLContext = nullptr;
}

void SUBTRA::Window::Maximize () const
{
    SDL_MaximizeWindow(SDLWindow);
}

void SUBTRA::Window::Clear () const
{
    SDL_GL_MakeCurrent(SDLWindow, SDLContext);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SUBTRA::Window::ResizeViewport (uint Width, uint Height)
{
    SDL_GL_MakeCurrent(SDLWindow, SDLContext);

    glViewport(0, 0, Width, Height);

    this->Width = Width;
    this->Height = Height;
}

void SUBTRA::Window::ProcessEvent (SDL_Event Event)
{
    SDL_GL_MakeCurrent(SDLWindow, SDLContext);

    if (Event.type == SDL_WINDOWEVENT && Event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        ResizeViewport(Event.window.data1, Event.window.data2);
    }
}

void SUBTRA::Window::BeginIMGUI ()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(SDLWindow);
    ImGui::NewFrame();
}

void SUBTRA::Window::UpdateIMGUI ()
{
    // ImGui::ShowDemoWindow(static_cast<bool *>(0));
}

void SUBTRA::Window::DrawIMGUI ()
{
    ImGui::End();
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SUBTRA::Window::Update ()
{
    
}

void SUBTRA::Window::Render ()
{
    
}

void SUBTRA::Window::SwapBuffers () const
{
    SDL_GL_SwapWindow(SDLWindow);
}