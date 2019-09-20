// SUBTRA Window class source
// 2019 Matthias Scherba @szczm_

#include "Window.hpp"

sub::Window::Window(const char* a_title, int a_width, int a_height)
{
    init(a_title, a_width, a_height);
}

void sub::Window::init(const char* a_title, int a_width, int a_height)
{
    m_SDLWindow.reset
    (
        SDL_CreateWindow
        (
            a_title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            a_width, a_height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
	    ),

        // passed to automatically destroy SDL_Window* inside
        SDL_DestroyWindow
    );

    if (!m_SDLWindow)
    {
        throw "Could not open window";
    }
}

void sub::Window::maximize()
{
    SDL_MaximizeWindow(m_SDLWindow.get());
}