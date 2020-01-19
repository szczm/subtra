// SUBTRA Camera component class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "Component.hpp"


namespace SUBTRA
{
    class Camera : public Component
    {
        public:

        void Init () override;
        void Update () override;
        void Destroy () override;
    };
}