// SUBTRA Parameter class source
// 2020 Matthias Scherba @szczm_

#include "Utilities/Parameter.hpp"

template<>
bool SUBTRA::Parameter<float>::UpdateIMGUI ()
{
    return ImGui::DragFloat(m_label, &m_value, m_stepValue, m_minValue, m_maxValue, "%.3f");
}