// SUBTRA Camera component class source
// 2020 Matthias Scherba @szczm_

#include "Components/Camera.hpp"

#include "imgui.h"

#include "Log.hpp"

SUBTRA::Camera::Camera (Object& a_object)
: Component(a_object)
{

}

void SUBTRA::Camera::Init ()
{
    // Log::Print("Camera init");
}

void SUBTRA::Camera::Update ()
{
    // Log::Print("Camera update");
}

void SUBTRA::Camera::UpdateIMGUI ()
{
    m_shouldUpdateMatrix |= m_fieldOfView.UpdateIMGUI()
                         || m_near.UpdateIMGUI()
                         || m_far.UpdateIMGUI();
}

void SUBTRA::Camera::Destroy ()
{
    // Log::Print("Camera destroy");
}

void SUBTRA::Camera::SetFieldOfView (float a_fieldOfView)
{
    m_fieldOfView = a_fieldOfView;

    m_shouldUpdateMatrix = true;
}

void SUBTRA::Camera::SetAspectRatio (float a_aspectRatio)
{
    m_aspectRatio = a_aspectRatio;

    m_shouldUpdateMatrix = true;
}

void SUBTRA::Camera::SetNear (float a_near)
{
    m_near = a_near;

    m_shouldUpdateMatrix = true;
}

void SUBTRA::Camera::SetFar (float a_far)
{
    m_far = a_far;

    m_shouldUpdateMatrix = true;
}

glm::mat4 SUBTRA::Camera::GetProjectionMatrix ()
{
    if (m_shouldUpdateMatrix)
    {
        UpdateMatrix();

        m_shouldUpdateMatrix = false;
    }

    return m_projectionMatrix;
}

void SUBTRA::Camera::UpdateMatrix ()
{
    m_projectionMatrix = glm::perspective(glm::radians(*m_fieldOfView), m_aspectRatio, *m_near, *m_far);
}