// SUBTRA Texture class source
// 2020 Matthias Scherba @szczm_

#include "Texture.hpp"

#include <iostream>
#include "Log.hpp"


SUBTRA::Texture SUBTRA::Texture::LoadFromFile (const std::string& a_path)
{
    FileSystem fileSystem;
    auto textureData = fileSystem.LoadTexture(a_path);

    if (textureData)
    {
        Texture texture;

        glGenTextures(1, &texture.m_tex);

        glBindTexture(GL_TEXTURE_2D, texture.m_tex);

        // TODO: do this somewhere else
        // TODO: more options?
        // TODO: use glTextureParameter after getting a new laptop? ._.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData->width, textureData->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData->data.get());
        glGenerateMipmap(GL_TEXTURE_2D);

        // TODO: just once?
        glActiveTexture(GL_TEXTURE0);

        return texture;
    }
    else
    {
        Log::Print("Texture ", a_path, " could not be loaded");

        return {};
    }
}

void SUBTRA::Texture::Bind ()
{
    glBindTexture(GL_TEXTURE_2D, m_tex);
}