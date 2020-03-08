// SUBTRA Component Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <functional>
#include <memory>

#include "Component.hpp"


namespace SUBTRA
{
    using ComponentPtr = std::weak_ptr<Component>;

    class ComponentManager final
    {
        public:

        static void AddComponent (ComponentPtr a_component)
        {
            m_components.push_back(a_component);
        }

        template <typename T>
        static std::vector<std::reference_wrapper<T>> GetComponents ()
        {
            std::vector<std::reference_wrapper<T>> components;

            for (auto it = m_components.begin(); it != m_components.end(); /**/)
            {
                if (auto component = it->lock())
                {
                    if (auto* Tcomponent = dynamic_cast<T*>(component.get()))
                    {
                        components.push_back(*Tcomponent);
                    }

                    ++it;
                }
                else
                {
                    it = m_components.erase(it);
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