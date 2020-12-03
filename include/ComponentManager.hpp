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

        inline static void AddComponent (std::weak_ptr<Component> Component)
        {
            AllComponents.push_back(Component);
        }

        // Ugly on the inside, beautiful on the outside. Usage example:
        // for (Camera& camera : ComponentManager::GetComponents<Camera>())
        template <typename ReturnType>
        static std::vector<std::reference_wrapper<ReturnType>> GetComponents ()
        {
            std::vector<std::reference_wrapper<ReturnType>> ComponentRefs;

            for (auto Iterator = AllComponents.begin(); Iterator != AllComponents.end(); /**/)
            {
                if (auto Component = Iterator->lock())
                {
                    if (auto* CastComponent = dynamic_cast<ReturnType*>(Component.get()))
                    {
                        ComponentRefs.push_back(*CastComponent);
                    }

                    ++Iterator;
                }
                else
                {
                    // Delete component if the reference to Iterator is no longer valid
                    Iterator = AllComponents.erase(Iterator);
                }
                
            }

            return ComponentRefs;
        }

        // Alias for getting all components
        inline static std::vector<std::reference_wrapper<Component>> GetComponents ()
        {
            return GetComponents<Component>();
        }


    private:

        inline static std::vector<std::weak_ptr<Component>> AllComponents {};
    };
}