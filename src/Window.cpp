// SUBTRA Window class source
// 2020 Matthias Scherba @szczm_

#include "Window.hpp"

#include "Exception.hpp"


SUBTRA::Window::Window (const std::string& a_title, int a_width, int a_height)
{
    Open(a_title, a_width, a_height);
}

void SUBTRA::Window::Open (const std::string& a_title, int a_width, int a_height)
{
    // Create window
    m_sdlWindow.reset
    (
        SDL_CreateWindow
        (
            a_title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            a_width, a_height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
        ),

        // Passing to automatically destroy SDL_Window* inside the smart pointer
        SDL_DestroyWindow
    );

    if (!m_sdlWindow)
    {
        throw SUBTRA::Exception {"Could not open window"};
    }

    // ...and create context
    m_sdlContext.reset
    (
        SDL_GL_CreateContext(m_sdlWindow.get()),
        SDL_GL_DeleteContext
    );

    if (!m_sdlContext)
    {
        throw SUBTRA::Exception {"Could not open context"};
    }

    SDL_GL_MakeCurrent(m_sdlWindow.get(), m_sdlContext.get());
}

void SUBTRA::Window::Maximize () const
{
    SDL_MaximizeWindow(m_sdlWindow.get());
}

// TODO: Assumes single window and context
void SUBTRA::Window::Clear () const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// TODO: Assumes single window and context
void SUBTRA::Window::ResizeViewport (int a_width, int a_height)
{
    glViewport(0, 0, a_width, a_height);

    m_width = a_width;
    m_height = a_height;
}

// TODO: Assumes single window and context
void SUBTRA::Window::ProcessEvent (const SDL_Event& a_event)
{
    if (a_event.type == SDL_WINDOWEVENT && a_event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        ResizeViewport(a_event.window.data1, a_event.window.data2);
    }
}

void SUBTRA::Window::UpdateIMGUI ()
{
    // foo.
}

void SUBTRA::Window::Render ()
{
    // bar.
}

void SUBTRA::Window::Swap () const
{
    SDL_GL_SwapWindow(m_sdlWindow.get());
}

std::weak_ptr<SDL_Window> SUBTRA::Window::GetSDLWindow () const
{
    return m_sdlWindow;
}

std::weak_ptr<SUBTRA::SDL_GLContext> SUBTRA::Window::GetContext () const
{
    return m_sdlContext;
}