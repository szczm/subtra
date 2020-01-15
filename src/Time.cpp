// SUBTRA Time class source
// 2020 Matthias Scherba @szczm_

#include "Time.hpp"

void SUBTRA::Time::UpdateValues()
{
    Uint32 ticks = SDL_GetTicks();

    if (m_lastTicks > 0)
    {
        deltaTime = (ticks - m_lastTicks) / 1000.0f;
    }

    time = ticks / 1000.0f;

    m_lastTicks = ticks;
}