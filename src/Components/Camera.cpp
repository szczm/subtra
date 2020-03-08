// SUBTRA Camera component class source
// 2020 Matthias Scherba @szczm_

#include "Components/Camera.hpp"

#include "Log.hpp"

SUBTRA::Camera::Camera(const Object& a_object)
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

void SUBTRA::Camera::Destroy ()
{
    // Log::Print("Camera destroy");
}

void SUBTRA::Camera::SetFoV (float a_fov)
{
    m_fov = a_fov;

    m_shouldUpdateProjectionMatrix = true;
}

void SUBTRA::Camera::SetAspect (float a_aspect)
{
    m_aspect = a_aspect;

    m_shouldUpdateProjectionMatrix = true;
}

glm::mat4 SUBTRA::Camera::GetProjectionMatrix ()
{
    if (m_shouldUpdateProjectionMatrix)
    {
        UpdateProjectionMatrix();

        m_shouldUpdateProjectionMatrix = false;
    }

    return m_projectionMatrix;
}

void SUBTRA::Camera::UpdateProjectionMatrix ()
{
    m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspect, 0.1f, 100.0f);
}