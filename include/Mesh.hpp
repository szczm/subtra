// SUBTRA Mesh class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <string>

#include "GLCommon.hpp"

namespace SUBTRA
{
    class Mesh
    {
        public:

        explicit Mesh (const std::string& a_path);
        Mesh () = default;
        ~Mesh () = default;

        void Bind ();

        enum VertexAttrib
        {
            Position = 0,
            Color = 1,
            TexCoord = 2
        };


        private:

        GLuint m_vao = 0;
        GLuint m_vbo = 0;
    };
}