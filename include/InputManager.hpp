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

        void Init() {};

        void ProcessEvent(const SDL_Event& a_event);

        private:

        void ProcessKeyboardEvent(const SDL_Event& a_event);
        void ProcessMouseEvent(const SDL_Event& a_event);
    };
}