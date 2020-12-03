// SUBTRA Window class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

#include "GLCommon.hpp"


namespace SUBTRA
{
    using SDL_GLContext = std::remove_pointer<SDL_GLContext>::type;

    class Window
    {

    public:

        // TODO: Implement move semantics in case more data is added to class
        static Window Open (const std::string& Title, uint Width, uint Height);

        void Maximize () const;
        void Clear () const;
        void SwapBuffers () const;
        void Resize (uint Width, uint Height);

        std::weak_ptr<SDL_Window> GetSDLWindow () const;
        std::weak_ptr<SDL_GLContext> GetContext () const;

        virtual void ProcessEvent (SDL_Event Event);
        virtual void UpdateIMGUI ();
        virtual void Render ();


    protected:
        
        void ResizeViewport (uint Width, uint Height);

        std::shared_ptr<SDL_Window> SDLWindow {};
        std::shared_ptr<SDL_GLContext> SDLContext {};

        uint Width = 0;
        uint Height = 0;

        // TODO: get rid of it? required for MainWindow::Open
        friend class MainWindow;
    };
}