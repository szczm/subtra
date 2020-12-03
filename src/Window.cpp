// SUBTRA Window class source
// 2020 Matthias Scherba @szczm_

#include "Window.hpp"

#include "Exception.hpp"
#include "Log.hpp"


SUBTRA::Window SUBTRA::Window::Open (const std::string& Title, uint Width, uint Height)
{
    Window NewWindow;

    // Create window
    NewWindow.SDLWindow.reset
    (
        SDL_CreateWindow
        (
            Title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            Width, Height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
        ),

        // Passing to automatically destroy SDL_Window* inside the smart pointer
        SDL_DestroyWindow
    );

    if (!NewWindow.SDLWindow)
    {
        throw SUBTRA::Exception("Could not open window");
    }

    // ...and create context
    NewWindow.SDLContext.reset
    (
        SDL_GL_CreateContext(NewWindow.SDLWindow.get()),
        SDL_GL_DeleteContext
    );

    if (!NewWindow.SDLContext)
    {
        throw SUBTRA::Exception("Could not open context");
    }

    SDL_GL_MakeCurrent(NewWindow.SDLWindow.get(), NewWindow.SDLContext.get());

    NewWindow.Height = Height;
    NewWindow.Width = Width;

    return NewWindow;
}

void SUBTRA::Window::Maximize () const
{
    SDL_MaximizeWindow(SDLWindow.get());
}

// TODO: Assumes single window and context
void SUBTRA::Window::Clear () const
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// TODO: Assumes single window and context
void SUBTRA::Window::ResizeViewport (uint Width, uint Height)
{
    glViewport(0, 0, Width, Height);

    this->Width = Width;
    this->Height = Height;
}

// TODO: Assumes single window and context
void SUBTRA::Window::ProcessEvent (SDL_Event Event)
{
    if (Event.type == SDL_WINDOWEVENT && Event.window.event == SDL_WINDOWEVENT_RESIZED)
    {
        ResizeViewport(Event.window.data1, Event.window.data2);
    }
}

void SUBTRA::Window::UpdateIMGUI ()
{

}

void SUBTRA::Window::Render ()
{
    
}

void SUBTRA::Window::SwapBuffers () const
{
    SDL_GL_SwapWindow(SDLWindow.get());
}

std::weak_ptr<SDL_Window> SUBTRA::Window::GetSDLWindow () const
{
    return SDLWindow;
}

std::weak_ptr<SUBTRA::SDL_GLContext> SUBTRA::Window::GetContext () const
{
    return SDLContext;
}