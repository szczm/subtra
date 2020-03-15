// SUBTRA Camera component class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "GLMCommon.hpp"

#include "Component.hpp"


namespace SUBTRA
{
    class Camera : public Component
    {
        public:

        Camera (const Object& a_object);

        void Init () override;
        void Update () override;
        void Destroy () override;

        void SetFoV (float a_fov);
        void SetAspect (float a_aspect);
        void SetNear (float a_near);
        void SetFar (float a_far);

        glm::mat4 GetProjectionMatrix ();


        private:

        void UpdateProjectionMatrix ();
        bool m_isDirty = true;

        glm::mat4 m_projectionMatrix = glm::mat4(1.0);

        float m_fov = 60.0f;
        float m_aspect = 1.0;
        float m_near = 0.1f;
        float m_far = 100.0f;
    };
}