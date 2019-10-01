// SUBTRA Shader class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"

namespace SUBTRA
{
    class Shader
    {
        public:

        Shader();
        ~Shader();
        
        Shader(const char* a_name, const char* a_vertexPath, const char* a_fragmentPath);

        void init(const char* a_name, const char* a_vertexPath, const char* a_fragmentPath);

        void use();


        private:

        const char* m_name;
        GLuint m_programID;
    };
}