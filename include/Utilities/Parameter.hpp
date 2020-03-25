// SUBTRA Parameter class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "imgui.h"


namespace SUBTRA
{
    template <typename Type>
    struct Parameter
    {
        Parameter (const char* a_label, Type a_initValue, Type a_stepValue, Type a_minValue, Type a_maxValue)
        : m_label(a_label),
          m_value(a_initValue),
          m_stepValue(a_stepValue),
          m_minValue(a_minValue),
          m_maxValue(a_maxValue)
        {

        }

        ~Parameter () = default;

        inline Parameter& operator= (Type a_value) { m_value = a_value; return *this; }
        inline Type& operator* () { return value; }

        bool UpdateIMGUI ();

        Type& value = m_value;


        private:
        
        Type m_value {};

        const char* m_label = nullptr;
        const Type m_stepValue {};
        const Type m_minValue {};
        const Type m_maxValue {};
    };
}