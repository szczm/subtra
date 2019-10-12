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

        Mesh() = default;
        ~Mesh() = default;

        void init();
        void bind();

        private:

        GLuint m_VAO = 0;
        GLuint m_VBO = 0;
    };
}