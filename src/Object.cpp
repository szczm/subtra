// SUBTRA Object class source
// 2020 Matthias Scherba @szczm_

#include "Object.hpp"


SUBTRA::Object::~Object ()
{
    for (auto* Component : Components)
    {
        delete Component;
    }
}

SUBTRA::Object& SUBTRA::Object::operator= (const SUBTRA::Object& Victim)
{
    if (&Victim == this)
    {
        return *this;
    }

    Components = Victim.Components;
    for (auto* Component : Components)
    {
        Component->Owner = this;
    }

    Transform = Victim.Transform;
    Transform.Owner = this;

    return *this;
}

