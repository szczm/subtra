// SUBTRA Mesh class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <string>

#include "GLCommon.hpp"

namespace SUBTRA
{
    enum VertexAttrib
    {
        Position = 0,
        Color = 1,
        TexCoord = 2
    };

    class Mesh
    {
        public:

        Mesh() = default;
        explicit Mesh(const std::string& a_path);

        ~Mesh() = default;

        void Bind();

        private:

        GLuint m_vao = 0;
        GLuint m_vbo = 0;
    };
}