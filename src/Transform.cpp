// SUBTRA Transform class source
// 2020 Matthias Scherba @szczm_

#include "Transform.hpp"

SUBTRA::Transform& SUBTRA::Transform::Reset ()
{
    m_localPosition = m_localAngles = {};
    m_localScale = {1.0, 1.0, 1.0};

    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetPosition (glm::vec3 a_position)
{
    m_localPosition = a_position;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetAngles (glm::vec3 a_angles)
{
    m_localAngles = a_angles;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetScale (glm::vec3 a_scale)
{
    m_localScale = a_scale;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetScale (float a_uniformScale)
{
    return SetScale(glm::vec3(a_uniformScale));
}

glm::vec3 SUBTRA::Transform::GetPosition () const
{
    return m_localPosition;
}

glm::vec3 SUBTRA::Transform::GetAngles () const
{
    return m_localAngles;
}

glm::vec3 SUBTRA::Transform::GetScale () const
{
    return m_localScale;
}

glm::mat4 SUBTRA::Transform::GetWorldMatrix ()
{
    if (m_shouldUpdateWorldMatrix)
    {
        UpdateWorldMatrix();

        m_shouldUpdateWorldMatrix = false;
    }

    return m_worldMatrix;
}


void SUBTRA::Transform::UpdateWorldMatrix ()
{
    glm::vec3 localAnglesRad = glm::radians(m_localAngles);

    glm::mat4 scale = glm::scale(glm::mat4(1.0), m_localScale);
    glm::mat4 rotate = glm::orientate4(localAnglesRad);
    glm::mat4 translate = glm::translate(glm::mat4(1.0), m_localPosition);

    m_worldMatrix = translate * rotate * scale;
}
