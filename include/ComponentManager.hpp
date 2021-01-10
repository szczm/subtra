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
        // TODO?: better lifetime management, if it becomes necessary

    public:

        inline static void AddComponent (Component* Component)
        {
            AllComponents.push_back(Component);
        }

        template <typename ComponentType>
        static std::vector<ComponentType*> GetComponents ()
        {
            std::vector<ComponentType*> Components;

            for (auto ComponentIt = AllComponents.begin(); ComponentIt != AllComponents.end(); /**/)
            {
                if (auto* CastComponent = dynamic_cast<ComponentType*>(*ComponentIt))
                {
                    Components.push_back(CastComponent);
                }

                ++ComponentIt;
            }

            return Components;
        }

        // Alias for getting all components
        inline static std::vector<Component*> GetComponents ()
        {
            return GetComponents<Component>();
        }

        inline static void RemoveComponent (Component* Component)
        {
            auto Position = std::find(AllComponents.begin(), AllComponents.end(), Component);

            if (Position != AllComponents.end())
            {
                AllComponents.erase(Position);
            }
        }


    private:

        inline static std::vector<Component*> AllComponents {};
    };
}