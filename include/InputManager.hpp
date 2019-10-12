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

        // No need to init/shutdown - no state yet
        // void init();
        // void shutdown();

        void processEvent(const SDL_Event& a_event);

        private:

        void processKeyboardEvent(const SDL_Event& a_event);
        void processMouseEvent(const SDL_Event& a_event);
    };
}