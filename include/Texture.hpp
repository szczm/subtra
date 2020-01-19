// SUBTRA Texture class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <string>

#include "FileSystem.hpp"
#include "GLCommon.hpp"


namespace SUBTRA
{
    class Texture
    {
        public:

        explicit Texture (const std::string& a_path);
        Texture () = default;
        ~Texture () = default;

        void Bind ();


        private:

        GLuint m_tex = 0;
    };
}