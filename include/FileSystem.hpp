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
    struct TextureData
    {
        int width, height, channels;
        std::shared_ptr<unsigned char> data;
    };

    class FileSystem final
    {
        public:

        FileSystem () = default;
        ~FileSystem () = default;

        std::optional<std::string> ReadText (const std::string& a_path) const;
        std::optional<TextureData> ReadTexture (const std::string& a_path) const;
    };
}