// SUBTRA Object class header
// 2019-2020 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <vector>

#include "Transform.hpp"

#include "Component.hpp"
#include "ComponentManager.hpp"


namespace SUBTRA
{
    class Object final
    {
    
    public:

        Object& operator= (const Object& Victim);

        template <class ComponentType>
        std::shared_ptr<ComponentType> AddComponent ()
        {
            auto Component = std::make_shared<ComponentType>(*this);

            Components.push_back(Component);
            ComponentManager::AddComponent(Component);

            return Component;
        }

        // NOTE: for now, assuming flat hierarchy. Add *World methods to Transform if changed.
        SUBTRA::Transform Transform {*this};

    private:
    
        std::vector<std::shared_ptr<Component>> Components {};
    };
}