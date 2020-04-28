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

        // TODO: Implement move func. in case more data is added to class
        static Window Open (const std::string& a_title, uint a_width, uint a_height);

        void Maximize () const;
        void Clear () const;
        void SwapBuffers () const;
        void Resize (uint a_width, uint a_height);

        std::weak_ptr<SDL_Window> GetSDLWindow () const;
        std::weak_ptr<SDL_GLContext> GetContext () const;

        virtual void ProcessEvent (SDL_Event a_event);
        virtual void UpdateIMGUI ();
        virtual void Render ();


        protected:
        
        void ResizeViewport (uint a_newWidth, uint a_newHeight);

        std::shared_ptr<SDL_Window> m_sdlWindow {};
        std::shared_ptr<SDL_GLContext> m_sdlContext {};

        uint m_width = 0;
        uint m_height = 0;


        friend class MainWindow;
    };
}