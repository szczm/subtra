// SUBTRA Object class header
// 2019-2020 Matthias Scherba @szczm_

#pragma once

#include "Transform.hpp"

namespace SUBTRA
{
    class Object
    {
        public:

        Object () = default;
        ~Object () = default;

        Transform & transform ();

        private:

        Transform m_transform {};
    };
}