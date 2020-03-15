// SUBTRA Time class source
// 2020 Matthias Scherba @szczm_

#include "Time.hpp"

void SUBTRA::Time::Update()
{
    Uint32 ticks = SDL_GetTicks();

    if (m_lastTicks > 0)
    {
        deltaTime = static_cast<float>(ticks - m_lastTicks) / 1000.0f;
    }

    time = static_cast<float>(ticks) / 1000.0f;

    m_lastTicks = ticks;
}