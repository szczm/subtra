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

        // TODO: Implement move semantics in case more data is added to class
        static Texture LoadFromFile(const std::string& PathToFile);

        void Bind ();

    private:

        GLuint TextureID = 0;
    };
}