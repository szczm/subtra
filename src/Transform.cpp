// SUBTRA Transform class source
// 2020 Matthias Scherba @szczm_

#include "Transform.hpp"

SUBTRA::Transform::Transform (Object& a_object)
: object(a_object)
{

}

SUBTRA::Transform& SUBTRA::Transform::Reset ()
{
    m_localPosition = m_localAngles = {};
    m_localScale = {1.0, 1.0, 1.0};

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetPosition (glm::vec3 a_position)
{
    m_localPosition = a_position;

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetAngles (glm::vec3 a_angles)
{
    m_localAngles = a_angles;

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetScale (glm::vec3 a_scale)
{
    m_localScale = a_scale;

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetScale (float a_uniformScale)
{
    return SetScale(glm::vec3(a_uniformScale));
}

SUBTRA::Transform& SUBTRA::Transform::Translate (glm::vec3 a_translation)
{
    m_localPosition += a_translation;

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::Rotate (glm::vec3 a_rotationAxis, float a_degrees)
{
    // TODO: Implement after switching to quaternions
    // m_localRotation *= glm::rotate();

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::Scale (glm::vec3 a_scale)
{
    m_localScale *= a_scale;

    m_isDirty = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::Scale (float a_uniformScale)
{
    m_localScale *= a_uniformScale;

    m_isDirty = true;
    return *this;
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
    if (m_isDirty)
    {
        UpdateWorldMatrix();

        m_isDirty = false;
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
