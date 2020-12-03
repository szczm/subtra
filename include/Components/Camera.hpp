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

        Camera (Object& Owner);

        void Initialize () override;
        void Update () override;
        void UpdateIMGUI () override;
        void Destroy () override;

        void SetFieldOfView (float FieldOfView);
        void SetAspectRatio (float AspectRatio);
        void SetNear (float Near);
        void SetFar (float Far);

        glm::mat4 GetProjectionMatrix ();


    private:

        glm::mat4 mProjectionMatrix = glm::mat4(1.0);

        Parameter<float> FieldOfView = Parameter {"FoV", 60.0f, 0.5f, 0.0f, 180.0f};
        Parameter<float> Near = Parameter {"Near", 0.1f, 0.1f, 0.0f, 100000.0f};
        Parameter<float> Far = Parameter {"Far", 10.0f, 0.1f, 0.0f, 100000.0f};

        float AspectRatio = 16.0f / 9.0f;
    };
}