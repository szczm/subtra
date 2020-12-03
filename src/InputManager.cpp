// SUBTRA Input Manager class header
// 2020 Matthias Scherba @szczm_

#include "InputManager.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"

void SUBTRA::InputManager::Initialize ()
{

}

void SUBTRA::InputManager::ProcessEvent (SDL_Event Event)
{
    // TODO: Check if ImGui was initialized
    ImGui_ImplSDL2_ProcessEvent(&Event);

    auto& ImGuiIO = ImGui::GetIO();

    if (ImGuiIO.WantCaptureKeyboard == false)
        ProcessKeyboardEvent(Event);

    if (ImGuiIO.WantCaptureMouse == false)
        ProcessMouseEvent(Event);
}

void SUBTRA::InputManager::ProcessKeyboardEvent (SDL_Event Event)
{

}

void SUBTRA::InputManager::ProcessMouseEvent (SDL_Event Event)
{

}