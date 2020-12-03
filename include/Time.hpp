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

        inline static float DeltaTime = 0.0f;
        inline static float TotalTime = 0.0f;

    private:

        Time () = delete;
        ~Time () = delete;

        static void Update ();

        inline static Uint32 LastTicks = 0.0f;

        friend Engine;
    };
}