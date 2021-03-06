// SUBTRA Component class source
// 2020 Matthias Scherba @szczm_

#include "Component.hpp"

#include "ComponentManager.hpp"


SUBTRA::Component::Component (Object& Owner)
: Owner(&Owner)
{
    ComponentManager::AddComponent(this);
}

SUBTRA::Component::~Component ()
{
    ComponentManager::RemoveComponent(this);
}