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

        explicit Window (const std::string& a_title, int a_width, int a_height);
        Window () = default;
        ~Window () = default;

        void Open (const std::string& a_title, int a_width, int a_height);
        void Maximize () const;
        void Clear () const;
        void Swap () const;
        void ResizeViewport (int a_width, int a_height);

        std::weak_ptr<SDL_Window> GetSDLWindow () const;
        std::weak_ptr<SDL_GLContext> GetContext () const;

        virtual void ProcessEvent (const SDL_Event& a_event);
        virtual void UpdateIMGUI ();
        virtual void Render ();


        protected:

        std::shared_ptr<SDL_Window> m_sdlWindow {};
        std::shared_ptr<SDL_GLContext> m_sdlContext {};

        int m_width = 0;
        int m_height = 0;
    };
}