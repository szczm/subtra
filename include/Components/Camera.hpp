// SUBTRA Camera component class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "GLMCommon.hpp"

#include "Component.hpp"
#include "Utilities/Parameter.hpp"


namespace SUBTRA
{
    class Camera : public Component
    {
        public:

        Camera (const Object& a_object);

        void Init () override;
        void Update () override;
        void UpdateIMGUI () override;
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

        Parameter<float> m_fov = Parameter {"FoV", 60.0f, 0.5f, 0.0f, 180.0f};
        Parameter<float> m_near = Parameter {"Near", 0.1f, 0.1f, 0.0f, 100000.0f};
        Parameter<float> m_far = Parameter {"Far", 10.0f, 0.1f, 0.0f, 100000.0f};

        float m_aspect = 1.0;
    };
}