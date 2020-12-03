// SUBTRA Transform class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "GLMCommon.hpp"

namespace SUBTRA
{
    class Object;
    
    class Transform final
    {

    public:

        // A Transform cannot exist without an Object, and vice versa
        Transform (Object& Owner);
        Transform () = delete;

        // Transform& operator=(const Transform& Victim);

        // Methods below return the current Transform to allowing chain calling
        Transform& Reset ();
        // Transform& Reset (Transform& Victim);
        Transform& SetLocalPosition (glm::vec3 LocalPosition);
        Transform& SetLocalRotation (glm::vec3 LocalRotation);
        Transform& SetLocalScale (glm::vec3 LocalScale);
        Transform& SetLocalScale (float LocalUniformScale);

        glm::vec3 GetLocalPosition () const;
        glm::vec3 GetLocalAngles () const;
        glm::vec3 GetLocalScale () const;

        glm::mat4 GetWorldMatrix ();


        Object* Owner = nullptr;

    private:

        glm::mat4 WorldMatrix = glm::mat4(1.0);

        glm::vec3 LocalPosition = glm::vec3(0.0f);
        glm::vec3 LocalRotation = glm::vec3(0.0f);
        glm::vec3 LocalScale = glm::vec3(1.0f);
    };
}