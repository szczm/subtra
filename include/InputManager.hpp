// SUBTRA Input Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <SDL2/SDL.h>

namespace SUBTRA
{
    class InputManager final
    {

    public:

        void Initialize ();

        void ProcessEvent (SDL_Event Event);

    private:

        void ProcessKeyboardEvent (SDL_Event Event);
        void ProcessMouseEvent (SDL_Event Event);
    };
}