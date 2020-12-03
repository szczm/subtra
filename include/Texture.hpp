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

        static Texture LoadFromFile(const std::string& PathToFile);

        void Bind ();

    private:

        GLuint TextureID = 0;

        int Width = 0;
        int Height = 0;
        int Channels = 0;
    };
}