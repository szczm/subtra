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
    m_isDirty |= m_fov.UpdateIMGUI()
              || m_near.UpdateIMGUI()
              || m_far.UpdateIMGUI();
}

void SUBTRA::Camera::Destroy ()
{
    // Log::Print("Camera destroy");
}

void SUBTRA::Camera::SetFoV (float a_fov)
{
    m_fov = a_fov;

    m_isDirty = true;
}

void SUBTRA::Camera::SetAspect (float a_aspect)
{
    m_aspect = a_aspect;

    m_isDirty = true;
}

void SUBTRA::Camera::SetNear (float a_near)
{
    m_near = a_near;

    m_isDirty = true;
}

void SUBTRA::Camera::SetFar (float a_far)
{
    m_far = a_far;

    m_isDirty = true;
}

glm::mat4 SUBTRA::Camera::GetProjectionMatrix ()
{
    if (m_isDirty)
    {
        UpdateProjectionMatrix();

        m_isDirty = false;
    }

    return m_projectionMatrix;
}

void SUBTRA::Camera::UpdateProjectionMatrix ()
{
    m_projectionMatrix = glm::perspective(glm::radians(*m_fov), m_aspect, *m_near, *m_far);
}