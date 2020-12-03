// SUBTRA Time class source
// 2020 Matthias Scherba @szczm_

#include "Time.hpp"

void SUBTRA::Time::Update()
{
    Uint32 Ticks = SDL_GetTicks();

    if (LastTicks > 0)
    {
        DeltaTime = static_cast<float>(Ticks - LastTicks) / 1000.0f;
    }

    TotalTime = static_cast<float>(Ticks) / 1000.0f;

    LastTicks = Ticks;
}