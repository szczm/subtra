// SUBTRA Window class source
// 2019 Matthias Scherba @szczm_

#include "Window.hpp"

#include "Exception.hpp"

SUBTRA::Window::Window(const std::string& a_title, int a_width, int a_height)
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
        throw SUBTRA::Exception {"Could not open window"};

    // ...and create context
    m_sdlContext.reset
    (
        SDL_GL_CreateContext(m_sdlWindow.get()),
        SDL_GL_DeleteContext
    );

    if (!m_sdlContext)
        throw SUBTRA::Exception {"Could not open context"};

    SDL_GL_MakeCurrent(m_sdlWindow.get(), m_sdlContext.get());

    // Try enabling adaptive vsync
    if (SDL_GL_SetSwapInterval(-1) < 0)
    {
        // If failed, fallback to vsync
        SDL_GL_SetSwapInterval(1);
    }
}

void SUBTRA::Window::Maximize() const
{
    SDL_MaximizeWindow(m_sdlWindow.get());
}

// TODO: Assumes single window and context
void SUBTRA::Window::Clear() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// TODO: Assumes single window and context
void SUBTRA::Window::ResizeViewport(int a_width, int a_height) const
{
    glViewport(0, 0, a_width, a_height);
}

void SUBTRA::Window::Swap() const
{
    SDL_GL_SwapWindow(m_sdlWindow.get());
}

std::shared_ptr<SDL_Window> SUBTRA::Window::GetSDLWindow() const
{
    return m_sdlWindow;
}

std::shared_ptr<SDL_GLContext_> SUBTRA::Window::GetContext() const
{
    return m_sdlContext;
}