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
        ~Shader() = default;
        
        Shader(const std::string& a_vertexPath, const std::string& a_fragmentPath);

        void init(const std::string& a_vertexPath, const std::string& a_fragmentPath);

        void use();


        private:

        GLuint m_programID = 0;
    };
}