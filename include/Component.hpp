// SUBTRA Component class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <memory>


namespace SUBTRA
{
    class Component
    {
        public:

        Component ();
        virtual ~Component () = 0;

        virtual void Init () = 0;
        virtual void Update () = 0;
        virtual void Destroy () = 0;
    };

    typedef std::shared_ptr<Component> ComponentPtr;
}