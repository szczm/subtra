// SUBTRA Transform class source
// 2020 Matthias Scherba @szczm_

#include "Transform.hpp"

SUBTRA::Transform::Transform (Object& Owner)
: Owner(&Owner)
{

}

SUBTRA::Transform& SUBTRA::Transform::Reset ()
{
    LocalPosition = glm::vec3(0.0f);
    LocalRotation = glm::vec3(0.0f);
    LocalScale = glm::vec3(1.0f);

    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetLocalPosition (glm::vec3 LocalPosition)
{
    this->LocalPosition = LocalPosition;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetLocalRotation (glm::vec3 LocalRotation)
{
    this->LocalRotation = LocalRotation;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetLocalScale (glm::vec3 LocalScale)
{
    this->LocalScale = LocalScale;
    return *this;
}

SUBTRA::Transform& SUBTRA::Transform::SetLocalScale (float LocalUniformScale)
{
    return SetLocalScale(glm::vec3(LocalUniformScale));
}


glm::vec3 SUBTRA::Transform::GetLocalPosition () const
{
    return LocalPosition;
}

glm::vec3 SUBTRA::Transform::GetLocalAngles () const
{
    return LocalRotation;
}

glm::vec3 SUBTRA::Transform::GetLocalScale () const
{
    return LocalScale;
}

glm::mat4 SUBTRA::Transform::GetWorldMatrix ()
{
    // NOTE: for now, assuming flat hierarchy. Adapt below if changed.
    glm::vec3 LocalAnglesRad = glm::radians(LocalRotation);

    glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0), LocalScale);
    glm::mat4 RotateMatrix = glm::orientate4(LocalAnglesRad);
    glm::mat4 TranslateMatrix = glm::translate(glm::mat4(1.0), LocalPosition);

    return TranslateMatrix * RotateMatrix * ScaleMatrix;
}