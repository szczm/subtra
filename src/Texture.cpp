// SUBTRA Texture class source
// 2019 Matthias Scherba @szczm_

#include "Texture.hpp"

#include <iostream>
#include "Log.hpp"


SUBTRA::Texture::Texture (const std::string& a_path)
{
    glGenTextures(1, &m_tex);

    glBindTexture(GL_TEXTURE_2D, m_tex);

    // TODO: do this somewhere else
    // TODO: more options?
    // TODO: use glTextureParameter after getting a new laptop? ._.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    FileSystem fileSystem;
    auto textureData = fileSystem.ReadTexture(a_path);

    if (textureData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData->width, textureData->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData->data.get());
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        Log::Print("Texture ", a_path, " could not be loaded");
    }

    // TODO: just once?
    glActiveTexture(GL_TEXTURE0);
}

void SUBTRA::Texture::Bind ()
{
    glBindTexture(GL_TEXTURE_2D, m_tex);
}