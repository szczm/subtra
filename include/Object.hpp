// SUBTRA Object class header
// 2019-2020 Matthias Scherba @szczm_

#pragma once

#include <memory>
#include <vector>

#include "Transform.hpp"

#include "Component.hpp"


namespace SUBTRA
{
    class Object final
    {
    
    public:

        ~Object ();

        Object& operator= (const Object& Victim);

        // TODO?: better lifetime management, if it becomes necessary
        template <class ComponentType>
        ComponentType* AddComponent ()
        {
            ComponentType* Component = new ComponentType {*this};
            
            Components.push_back(Component);

            return Component;
        }

        // NOTE: for now, assuming a flat hierarchy. Add *World methods to Transform if changed.
        SUBTRA::Transform Transform {*this};

    private:
    
        std::vector<Component*> Components {};
    };
}