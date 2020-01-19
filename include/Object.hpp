// SUBTRA Object class header
// 2019-2020 Matthias Scherba @szczm_

#pragma once

#include <vector>

#include "Transform.hpp"

#include "Component.hpp"
#include "ComponentManager.hpp"


namespace SUBTRA
{
    class Object
    {
        public:

        Object () = default;
        ~Object () = default;

        Transform& transform ();

        template <class T>
        void AddComponent ()
        {
            m_components.push_back(ComponentManager::AddComponent<T>());
        }


        private:

        Transform m_transform {};
        std::vector<ComponentPtr> m_components {};
    };
}