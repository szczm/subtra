// SUBTRA Mesh class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"

namespace SUBTRA
{
    enum VertexAttrib
    {
        Position = 0
    };

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