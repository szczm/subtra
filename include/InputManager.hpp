// SUBTRA Input Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <SDL2/SDL.h>

namespace SUBTRA
{
    class InputManager final
    {
        public:

        InputManager () = default;
        ~InputManager () = default;

        void Init ();

        void ProcessEvent (SDL_Event a_event);


        private:

        void ProcessKeyboardEvent (SDL_Event a_event);
        void ProcessMouseEvent (SDL_Event a_event);
    };
}