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

        enum VertexAttrib
        {
            Position = 0,
            Color = 1,
            TexCoord = 2
        };

        static Mesh LoadFromFile (const std::string& PathToFile);

        void Bind ();


    private:

        GLuint VAO = 0;
        GLuint VBO = 0;
    };
}