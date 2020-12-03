// SUBTRA Texture class source
// 2020 Matthias Scherba @szczm_

#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Log.hpp"


SUBTRA::Texture SUBTRA::Texture::LoadFromFile (const std::string& PathToFile)
{
    FileSystem FileSystem;
    auto Text = FileSystem.LoadText(PathToFile);

    if (!Text)
    {
        Log::Error("Could not open texture file: ", PathToFile);

        return {};
    }

    Texture NewTexture;

    stbi_set_flip_vertically_on_load(1);
    stbi_uc* Data = stbi_load_from_memory(
        reinterpret_cast<const unsigned char*>(Text->c_str()), Text->length(),
        &NewTexture.Width, &NewTexture.Height, &NewTexture.Channels,
        STBI_rgb_alpha
    );

    if (Data == nullptr)
    {
        Log::Error("Could not load texture file: ", PathToFile);

        return {};
    }

    glGenTextures(1, &NewTexture.TextureID);

    glBindTexture(GL_TEXTURE_2D, NewTexture.TextureID);

    // TODO: add options?
    // TODO: use glTextureParameter after getting a new laptop? ._.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, NewTexture.Width, NewTexture.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(Data);

    // TODO: support for multiple textures
    glActiveTexture(GL_TEXTURE0);

    return NewTexture;
}

void SUBTRA::Texture::Bind ()
{
    glBindTexture(GL_TEXTURE_2D, TextureID);
}