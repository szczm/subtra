// SUBTRA InputManager class header
// 2019 Matthias Scherba @szczm_

#include "InputManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"

void SUBTRA::InputManager::Init () {}

void SUBTRA::InputManager::ProcessEvent (const SDL_Event& a_event)
{
    // TODO: Check if ImGui was initialized
    ImGui_ImplSDL2_ProcessEvent(&a_event);

    auto& imGuiIO = ImGui::GetIO();

    if (imGuiIO.WantCaptureKeyboard == false)
        ProcessKeyboardEvent(a_event);

    if (imGuiIO.WantCaptureMouse == false)
        ProcessMouseEvent(a_event);
}

void SUBTRA::InputManager::ProcessKeyboardEvent (const SDL_Event& a_event) {}
void SUBTRA::InputManager::ProcessMouseEvent (const SDL_Event& a_event) {}