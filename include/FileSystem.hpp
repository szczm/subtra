// SUBTRA File System class header
// 2020 Matthias Scherba @szczm_

#pragma once

// #include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include <optional>
#include <string>

namespace SUBTRA
{
    using byte = unsigned char;

    class FileSystem final
    {

    private:

        struct TextureData
        {
            int Width, Height, Channels;
            std::shared_ptr<byte> Data;
        };
        
    public:

        std::optional<std::string> LoadText (const std::string& PathToFile);
        std::optional<TextureData> LoadTexture (const std::string& PathToFile);
    };
}