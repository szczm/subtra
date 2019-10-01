// SUBTRA Window class source
// 2019 Matthias Scherba @szczm_

#include "Window.hpp"

#include "Exception.hpp"

sub::Window::Window(const char* a_title, int a_width, int a_height)
{
    init(a_title, a_width, a_height);
}

// Extracted to allow deferred window initialization
void sub::Window::init(const char* a_title, int a_width, int a_height)
{
    // Create window
    m_SDLWindow.reset
    (
        SDL_CreateWindow
        (
            a_title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            a_width, a_height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
	    ),

        // Passing to automatically destroy SDL_Window* inside the smart pointer
        SDL_DestroyWindow
    );

    if (!m_SDLWindow)
    {
        throw sub::Exception("Could not open window");
    }

    // ...and create context
    m_SDLContext.reset
    (
        SDL_GL_CreateContext(m_SDLWindow.get()),
        SDL_GL_DeleteContext
    );

    if (!m_SDLContext)
    {
        throw sub::Exception("Could not open context");
    }

    // Try enabling adaptive vsync
    if (SDL_GL_SetSwapInterval(-1) < 0)
    {
        // If failed, fallback to vsync
        SDL_GL_SetSwapInterval(1);
    }
}

void sub::Window::maximize() const
{
    SDL_MaximizeWindow(m_SDLWindow.get());
}

// TODO: Assumes single window and context
void sub::Window::clear() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// TODO: Assumes single window and context
void sub::Window::resizeViewport(int a_width, int a_height) const
{
    glViewport(0, 0, a_width, a_height);
}

void sub::Window::swap() const
{
    SDL_GL_SwapWindow(m_SDLWindow.get());
}