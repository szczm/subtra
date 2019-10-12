// SUBTRA InputManager class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <SDL2/SDL.h>

namespace SUBTRA
{
    class InputManager
    {
        public:

        InputManager() = default;
        ~InputManager() = default;

        void init() {};

        void processEvent(const SDL_Event& a_event);

        private:

        void processKeyboardEvent(const SDL_Event& a_event);
        void processMouseEvent(const SDL_Event& a_event);
    };
}