// SUBTRA Component class source
// 2020 Matthias Scherba @szczm_

#include "Component.hpp"

// #include "ComponentManager.hpp"


SUBTRA::Component::Component (const Object& a_object)
 : m_object(a_object)
{
    // ComponentManager::AddComponent(ComponentPointer(this));
}

SUBTRA::Component::~Component ()
{
    // ComponentManager::RemoveComponent(ComponentPointer(this));
}