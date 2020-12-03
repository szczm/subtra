// SUBTRA Camera component class source
// 2020 Matthias Scherba @szczm_

#include "Components/Camera.hpp"

#include "imgui.h"

#include "Log.hpp"

SUBTRA::Camera::Camera (Object& Owner)
: Component(Owner)
{

}

void SUBTRA::Camera::Initialize ()
{
    // Log::Print("Camera init");
}

void SUBTRA::Camera::Update ()
{
    // Log::Print("Camera update");
}

void SUBTRA::Camera::UpdateIMGUI ()
{
    FieldOfView.UpdateIMGUI();
    Near.UpdateIMGUI();
    Far.UpdateIMGUI();
}

void SUBTRA::Camera::Destroy ()
{
    // Log::Print("Camera destroy");
}

void SUBTRA::Camera::SetFieldOfView (float FieldOfView)
{
    this->FieldOfView = FieldOfView;
}

void SUBTRA::Camera::SetAspectRatio (float AspectRatio)
{
    this->AspectRatio = AspectRatio;
}

void SUBTRA::Camera::SetNear (float Near)
{
    this->Near = Near;
}

void SUBTRA::Camera::SetFar (float Far)
{
    this->Far = Far;
}

glm::mat4 SUBTRA::Camera::GetProjectionMatrix ()
{
    return glm::perspective(glm::radians(FieldOfView.Value), AspectRatio, Near.Value, Far.Value);
}