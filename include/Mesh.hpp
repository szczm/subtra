// SUBTRA Mesh class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <string>

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
        explicit Mesh(const std::string& a_path);

        ~Mesh() = default;

        void bind();

        private:

        GLuint m_VAO = 0;
        GLuint m_VBO = 0;
    };
}