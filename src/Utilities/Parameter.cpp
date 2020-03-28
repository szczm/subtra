// SUBTRA Parameter class source
// 2020 Matthias Scherba @szczm_

#include "Utilities/Parameter.hpp"

#include "Utilities/Color.hpp"


template<>
bool SUBTRA::Parameter<float>::UpdateIMGUI ()
{
    return ImGui::DragFloat(m_label, &m_value, m_stepValue, m_minValue, m_maxValue, "%.3f");
}

template<>
bool SUBTRA::Parameter<SUBTRA::Color>::UpdateIMGUI ()
{
    return ImGui::ColorEdit4(m_label, static_cast<float*>(&m_value.red));
}