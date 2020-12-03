// SUBTRA Window class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

#include "GLCommon.hpp"


namespace SUBTRA
{
    class Window
    {

    public:

        static Window Open (const std::string& Title, uint Width, uint Height);

        Window () = default;
        virtual ~Window ();
        // and the Four Horsemen of Apocalypse
        Window (Window&) = delete;
        Window (Window&&); 
        Window& operator= (Window&) = delete;
        Window& operator= (Window&&);

        void Maximize () const;
        void Clear () const;
        void SwapBuffers () const;
        void Resize (uint Width, uint Height);

        virtual void ProcessEvent (SDL_Event Event);
        virtual void Update ();
        virtual void Render ();

        // You should probably never implement the Begin/Draw functions, but they are virtual just in case.
        virtual void BeginIMGUI ();
        virtual void UpdateIMGUI ();
        virtual void DrawIMGUI ();


    protected:
        
        void ResizeViewport (uint Width, uint Height);

public:
        SDL_Window* SDLWindow = nullptr;
        SDL_GLContext SDLContext = nullptr;
        protected:

        uint Width = 0;
        uint Height = 0;

        // TODO?: get rid of it? required for MainWindow::Open
        friend class MainWindow;
    };
}