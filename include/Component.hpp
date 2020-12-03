// SUBTRA Component class header
// 2020 Matthias Scherba @szczm_

#pragma once


namespace SUBTRA
{
    class Object;

    class Component
    {

    public:

        // Require an owning object for Component
        Component (Object& Owner);
        Component () = delete;

        virtual ~Component () = 0;

        virtual void Initialize () = 0;
        virtual void Update () = 0;
        virtual void UpdateIMGUI () = 0;
        virtual void Destroy () = 0;

        Object* Owner = nullptr;
        
    };
}