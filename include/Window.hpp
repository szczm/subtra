// SUBTRA Window class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

#include "GLCommon.hpp"

namespace sub
{
    class Window
    {
        public:

        inline Window() {};
        inline ~Window() {};
        
        Window(const char* a_title, int a_width, int a_height);

        void init(const char* a_title, int a_width, int a_height);

        void maximize() const;
        void clear() const;
        void swap() const;

        void resizeViewport(int a_width, int a_height) const;

        // inline std::weak_ptr<SDL_Window> getSDLWindow() const { return m_SDLWindow; };


        private:

        std::shared_ptr<SDL_Window> m_SDLWindow;
        std::shared_ptr<std::remove_pointer<SDL_GLContext>::type> m_SDLContext;
    };
}