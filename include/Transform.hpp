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

        Transform (Object& a_object);
        Transform () = delete;
        ~Transform () = default;

        Transform& Reset ();
        // Transform& Reset (Transform& a_template);

        Transform& SetPosition (glm::vec3 a_position);
        Transform& SetAngles (glm::vec3 a_angles);
        Transform& SetScale (glm::vec3 a_scale);
        Transform& SetScale (float a_uniformScale);

        Transform& Translate (glm::vec3 a_translation);
        Transform& Rotate (glm::vec3 a_rotationAxis, float a_degrees);
        Transform& Scale (glm::vec3 a_scale);
        Transform& Scale (float a_uniformScale);

        glm::vec3 GetPosition () const;
        glm::vec3 GetAngles () const;
        glm::vec3 GetScale () const;

        glm::mat4 GetWorldMatrix ();


        Object& object;


        private:

        void UpdateWorldMatrix ();
        bool m_isDirty = true;

        glm::mat4 m_worldMatrix = glm::mat4(1.0);

        glm::vec3 m_localPosition {};
        glm::vec3 m_localAngles {};
        glm::vec3 m_localScale {1.0, 1.0, 1.0};
    };
}