// SUBTRA Window class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

#include "GLCommon.hpp"


namespace SUBTRA
{
    typedef std::remove_pointer<SDL_GLContext>::type SDL_GLContext_;

    class Window
    {
        public:

        Window() = default;
        explicit Window(const std::string& a_title, int a_width, int a_height);

        ~Window() = default;

        void Open(const std::string& a_title, int a_width, int a_height);
        void Maximize() const;
        void Clear() const;
        void Swap() const;
        void ResizeViewport(int a_width, int a_height) const;

        virtual void ProcessEvent(const SDL_Event& a_event);
        virtual void UpdateIMGUI();
        virtual void Render();

        std::shared_ptr<SDL_Window> GetSDLWindow() const;
        std::shared_ptr<SDL_GLContext_> GetContext() const;

        protected:

        std::shared_ptr<SDL_Window> m_sdlWindow {};
        std::shared_ptr<SDL_GLContext_> m_sdlContext {};
    };
}