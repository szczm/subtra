// SUBTRA Texture class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include <string>

#include "FileSystem.hpp"
#include "GLCommon.hpp"


namespace SUBTRA
{
    class Texture
    {
        public:

        Texture () = default;
        explicit Texture (const std::string& a_path);

        ~Texture () = default;

        void Bind ();

        private:

        GLuint m_tex = 0;
    };
}