// SUBTRA Parameter class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "imgui.h"


namespace SUBTRA
{
    // Parameter holds a value of a specified type and exposes it to the user through IMGUI almost automagically.
    //
    // Unsupported types are added by implementing their respective UpdateIMGUI method in Parameter.cpp
    template <typename Type>
    class Parameter
    {
        public:

        Parameter (const char* a_label, Type a_initValue = {}, Type a_stepValue = {}, Type a_minValue = {}, Type a_maxValue = {})
        : value(m_value),
          m_label(a_label),
          m_value(a_initValue),
          m_stepValue(a_stepValue),
          m_minValue(a_minValue),
          m_maxValue(a_maxValue)
        {

        }

        Parameter (const Parameter& a_other)
        : value(m_value),
          m_label(a_other.m_label),
          m_value(a_other.m_value),
          m_stepValue(a_other.m_stepValue),
          m_minValue(a_other.m_minValue),
          m_maxValue(a_other.m_maxValue)
        {

        }

        Parameter& operator= (const Parameter& a_other)
        {
           m_label = a_other.m_label;
           m_value = a_other.m_value;
           m_stepValue = a_other.m_stepValue;
           m_minValue = a_other.m_minValue;
           m_maxValue = a_other.m_maxValue;

           return *this;
        }

        ~Parameter () = default;

        // Easy access/assignment semantics
        inline Parameter& operator= (Type a_value) { m_value = a_value; return *this; }
        inline Type& operator* () { return value; }

        // Returns true if value was changed through GUI interaction
        bool UpdateIMGUI ();

        // Pretty alias for direct access to underlying value
        Type& value = m_value;


        private:
        
        const char* m_label = nullptr;
        
        Type m_value {};
        Type m_stepValue {};
        Type m_minValue {};
        Type m_maxValue {};
    };
}