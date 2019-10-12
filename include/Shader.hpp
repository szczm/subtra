// SUBTRA Shader class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"

#include <string>

namespace SUBTRA
{
    class Shader
    {
        public:

        Shader() = default;
        explicit Shader(const std::string& a_vertexPath, const std::string& a_fragmentPath);

        ~Shader() = default;

        void use();

        private:

        GLuint m_programID = 0;
    };
}