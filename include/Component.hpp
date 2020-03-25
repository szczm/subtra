// SUBTRA Component class header
// 2020 Matthias Scherba @szczm_

#pragma once


namespace SUBTRA
{
    class Object;

    class Component
    {
        public:

        explicit Component (const Object& a_object);
        virtual ~Component () = 0;

        virtual void Init () = 0;
        virtual void Update () = 0;
        virtual void UpdateIMGUI () = 0;
        virtual void Destroy () = 0;

        const Object& m_object;
    };
}