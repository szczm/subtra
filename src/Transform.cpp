// SUBTRA Transform class source
// 2019-2020 Matthias Scherba @szczm_

#include "Transform.hpp"

SUBTRA::Transform& SUBTRA::Transform::reset ()
{
    m_localPosition = m_localAngles = {};
    m_localScale = {1.0, 1.0, 1.0};

    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::setPosition (glm::vec3 a_position)
{
    m_localPosition = a_position;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::setAngles (glm::vec3 a_angles)
{
    m_localAngles = a_angles;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::setScale (glm::vec3 a_scale)
{
    m_localScale = a_scale;

    m_shouldUpdateWorldMatrix = true;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::setScale (float a_uniformScale)
{
    return setScale(glm::vec3(a_uniformScale));
}

glm::vec3 SUBTRA::Transform::getPosition () const
{
    return m_localPosition;
}

glm::vec3 SUBTRA::Transform::getAngles () const
{
    return m_localAngles;
}

glm::vec3 SUBTRA::Transform::getScale () const
{
    return m_localScale;
}

glm::mat4 SUBTRA::Transform::getWorldMatrix ()
{
    if (m_shouldUpdateWorldMatrix)
    {
        updateWorldMatrix();

        m_shouldUpdateWorldMatrix = false;
    }

    return m_worldMatrix;
}


void SUBTRA::Transform::updateWorldMatrix ()
{
    glm::vec3 localAnglesRad = glm::radians(m_localAngles);

    m_worldMatrix = glm::scale(glm::mat4(1.0), m_localScale);
    m_worldMatrix = glm::orientate4(localAnglesRad) * m_worldMatrix;
    m_worldMatrix = glm::translate(m_worldMatrix, m_localPosition);
}
