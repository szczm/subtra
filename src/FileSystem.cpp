// SUBTRA File System class header
// 2020 Matthias Scherba @szczm_

#include "FileSystem.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::optional<std::string> SUBTRA::FileSystem::LoadText (const std::string& PathToFile)
{
    // Experimental because GCC 7 :(
    using std::experimental::filesystem::file_size;

    if (std::ifstream stream(PathToFile); stream.good())
    {
        auto FileSize = file_size(PathToFile.c_str());

        std::string Content (FileSize, '\0');
        stream.read(Content.data(), FileSize);

        return Content;
    }

    return {};
}

std::optional<SUBTRA::FileSystem::TextureData> SUBTRA::FileSystem::LoadTexture (const std::string& PathToFile)
{
    auto Text = LoadText(PathToFile);

    if (Text)
    {
        TextureData NewTextureData;

        // TODO: extract image code to a separate class?
        stbi_set_flip_vertically_on_load(1);

        NewTextureData.Data.reset
        (
            stbi_load_from_memory
            (
                reinterpret_cast<const unsigned char*>(Text->c_str()), Text->length(),
                &NewTextureData.Width, &NewTextureData.Height, &NewTextureData.Channels, STBI_rgb_alpha
            )
        );

        return NewTextureData;
    }

    return {};
}