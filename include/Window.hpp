// SUBTRA Window class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

#include "GLCommon.hpp"


typedef std::remove_pointer<SDL_GLContext>::type SDL_GLContext_;

namespace SUBTRA
{
    class Window
    {
        public:

        Window() = default;
        explicit Window(const std::string& a_title, int a_width, int a_height);

        ~Window() = default;

        void maximize() const;
        void clear() const;
        void swap() const;

        void resizeViewport(int a_width, int a_height) const;

        std::shared_ptr<SDL_Window> getSDLWindow() const;
        std::shared_ptr<SDL_GLContext_> getContext() const;

        private:

        std::shared_ptr<SDL_Window> m_SDLWindow {};
        std::shared_ptr<SDL_GLContext_> m_SDLContext {};
    };
}