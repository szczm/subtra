// SUBTRA Transform class header
// 2019-2020 Matthias Scherba @szczm_

#pragma once

#include "GLMCommon.hpp"

namespace SUBTRA
{
    class Transform
    {
        public:

        Transform () = default;
        ~Transform () = default;

        Transform& reset ();
        // Transform& reset(Transform& a_template);

        Transform& setPosition (glm::vec3 a_position);
        Transform& setAngles (glm::vec3 a_angles);
        Transform& setScale (glm::vec3 a_scale);
        Transform& setScale (float a_uniformScale);

        glm::vec3 getPosition () const;
        glm::vec3 getAngles () const;
        glm::vec3 getScale () const;

        glm::mat4 getWorldMatrix ();

        private:

        void updateWorldMatrix ();
        bool m_shouldUpdateWorldMatrix = false;

        glm::mat4 m_worldMatrix = glm::mat4(1.0);

        glm::vec3 m_localPosition {};
        glm::vec3 m_localAngles {};
        glm::vec3 m_localScale {1.0, 1.0, 1.0};
    };
}