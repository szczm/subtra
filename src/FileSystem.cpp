// SUBTRA FileSystem class header
// 2019 Matthias Scherba @szczm_

#include "FileSystem.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::optional<std::string> SUBTRA::FileSystem::ReadText(const std::string& a_path) const
{
    // Experimental because GCC 7 :(
    using std::experimental::filesystem::file_size;

    if (std::ifstream stream {a_path}; stream.good())
    {
        auto filesize = file_size(a_path.c_str());

        std::string content (filesize, '\0');
        stream.read(content.data(), filesize);

        return content;
    }

    return {};
}

std::optional<SUBTRA::TextureData> SUBTRA::FileSystem::ReadTexture(const std::string& a_path) const
{
    auto text = ReadText(a_path);

    if (text)
    {
        TextureData textureData;

        // TODO: extract image code to a separate class?
        stbi_set_flip_vertically_on_load(1);

        textureData.data.reset
        (
            stbi_load_from_memory
            (
                reinterpret_cast<const unsigned char*>(text->c_str()), text->length(),
                &textureData.width, &textureData.height, &textureData.channels, STBI_rgb_alpha
            )
        );

        return textureData;
    }

    return {};
}