// SUBTRA Parameter class source
// 2020 Matthias Scherba @szczm_

#include "Utilities/Parameter.hpp"

#include "Utilities/Color.hpp"


template<>
bool SUBTRA::Parameter<float>::UpdateIMGUI ()
{
    return ImGui::DragFloat(Label, &Value, Step, Min, Max, "%.3f");
}

template<>
bool SUBTRA::Parameter<SUBTRA::Color>::UpdateIMGUI ()
{
    return ImGui::ColorEdit4(Label, static_cast<float*>(&Value.Red));
}