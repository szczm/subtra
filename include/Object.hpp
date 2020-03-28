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

        template <class T>
        std::shared_ptr<T> AddComponent ()
        {
            auto component = std::make_shared<T>(*this);

            m_components.push_back(component);
            ComponentManager::AddComponent(component);

            return component;
        }

        Transform& transform = m_transform;


        private:

        Transform m_transform {*this};
        std::vector<std::shared_ptr<Component>> m_components {};
    };
}