// SUBTRA Texture class source
// 2020 Matthias Scherba @szczm_

#include "Texture.hpp"

#include <iostream>
#include "Log.hpp"


SUBTRA::Texture SUBTRA::Texture::LoadFromFile (const std::string& PathToFile)
{
    FileSystem FileSystem;
    auto TextureData = FileSystem.LoadTexture(PathToFile);

    if (TextureData)
    {
        Texture NewTexture;

        glGenTextures(1, &NewTexture.TextureID);

        glBindTexture(GL_TEXTURE_2D, NewTexture.TextureID);

        // TODO: do this somewhere else
        // TODO: more options?
        // TODO: use glTextureParameter after getting a new laptop? ._.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextureData->Width, TextureData->Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, TextureData->Data.get());
        glGenerateMipmap(GL_TEXTURE_2D);

        // TODO: just once?
        glActiveTexture(GL_TEXTURE0);

        return NewTexture;
    }
    else
    {
        Log::Error("Could not open texture file: ", PathToFile);

        return {};
    }
}

void SUBTRA::Texture::Bind ()
{
    glBindTexture(GL_TEXTURE_2D, TextureID);
}