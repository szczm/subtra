// SUBTRA Window class header
// 2019 Matthias Scherba @szczm_

#include <memory>

#include <SDL2/SDL.h>

namespace sub
{
    class Window
    {
        private:

        std::shared_ptr<SDL_Window> m_SDLWindow;

        public:

        Window() {};
        Window(const char* a_title, int a_width, int a_height);
        ~Window() {};

        void init(const char* a_title, int a_width, int a_height);
        void maximize();

        inline std::weak_ptr<SDL_Window> getSDLWindow() { return m_SDLWindow; };
    };
}