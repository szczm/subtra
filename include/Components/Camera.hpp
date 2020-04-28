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

        Camera (Object& a_object);

        void Init () override;
        void Update () override;
        void UpdateIMGUI () override;
        void Destroy () override;

        void SetFieldOfView (float a_fieldOfView);
        void SetAspectRatio (float a_aspectRatio);
        void SetNear (float a_near);
        void SetFar (float a_far);

        glm::mat4 GetProjectionMatrix ();


        private:

        // Cache the projection matrix and update it only when needed
        void UpdateMatrix ();
        bool m_shouldUpdateMatrix = true;

        glm::mat4 m_projectionMatrix = glm::mat4(1.0);

        Parameter<float> m_fieldOfView = Parameter {"Field of view", 60.0f, 0.5f, 0.0f, 180.0f};
        Parameter<float> m_near = Parameter {"Near", 0.1f, 0.1f, 0.0f, 100000.0f};
        Parameter<float> m_far = Parameter {"Far", 10.0f, 0.1f, 0.0f, 100000.0f};

        float m_aspectRatio = 1.0;
    };
}