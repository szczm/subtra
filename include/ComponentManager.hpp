// SUBTRA Component Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <functional>
#include <memory>

#include "Component.hpp"


namespace SUBTRA
{
    class ComponentManager final
    {
        public:

        inline static void AddComponent (std::weak_ptr<Component> a_component)
        {
            m_components.push_back(a_component);
        }

        // This may look bad at a first glance, but it allows very clean usage on site:
        //   for (Camera& camera : ComponentManager::GetComponents<Camera>())
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
                    // Delete component if the reference to it is no longer valid
                    it = m_components.erase(it);
                }
                
            }

            return components;
        }

        // Alias for getting all components
        inline static std::vector<std::reference_wrapper<Component>> GetComponents ()
        {
            return GetComponents<Component>();
        }


        private:

        inline static std::vector<std::weak_ptr<Component>> m_components {};
    };
}