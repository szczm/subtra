// SUBTRA Window class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <type_traits>

#include <SDL2/SDL.h>

namespace sub
{
    class Window
    {
        private:

        std::shared_ptr<SDL_Window> m_SDLWindow;
        std::shared_ptr<std::remove_pointer<SDL_GLContext>::type> m_SDLContext;

        public:

        Window() {};
        Window(const char* a_title, int a_width, int a_height);
        ~Window() {};

        void init(const char* a_title, int a_width, int a_height);
        void maximize() const;

        inline std::weak_ptr<SDL_Window> getSDLWindow() const { return m_SDLWindow; };
    };
}