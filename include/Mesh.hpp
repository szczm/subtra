// SUBTRA Mesh class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"

namespace SUBTRA
{
    class Mesh
    {
        public:

        Mesh();
        ~Mesh();

        void init();
        void bind();

        private:

        GLuint m_VAO;
        GLuint m_VBO;
    };
}