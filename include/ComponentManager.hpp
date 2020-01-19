// SUBTRA Component Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <functional>
#include <memory>

#include "Component.hpp"


namespace SUBTRA
{
    class ComponentManager
    {
        public:

        template <class T>
        static ComponentPtr AddComponent ()
        {
            auto component = std::make_shared<T>();
            m_components.push_back(component);

            return component;
        }

        template <typename T>
        static std::vector<std::reference_wrapper<T>> GetComponents ()
        {
            std::vector<std::reference_wrapper<T>> components;

            for (ComponentPtr component : m_components)
            {
                if (auto* Tcomponent = dynamic_cast<T*>(component.get()))
                {
                    components.push_back(*Tcomponent);
                }
            }

            return components;
        }

        static std::vector<std::reference_wrapper<Component>> GetComponents ()
        {
            return GetComponents<Component>();
        }


        private:

        inline static std::vector<ComponentPtr> m_components {};
    };
}