// SUBTRA Time class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "Engine.hpp"

#include <SDL2/SDL.h>

namespace SUBTRA
{
    class Time final
    {
        public:

        inline static float deltaTime = 0.0f;
        inline static float time = 0.0f;

        friend Engine;


        private:

        Time() = delete;
        ~Time() = default;

        static void UpdateValues();

        inline static Uint32 m_lastTicks = 0.0f;
    };
}