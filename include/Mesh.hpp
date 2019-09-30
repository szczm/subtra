// SUBTRA Mesh class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"

namespace sub
{
    class Mesh
    {
        public:

        inline Mesh() {};
        inline ~Mesh() {};

        void init();
        void bind();

        private:

        GLuint m_VAO;
        GLuint m_VBO;
    };
}