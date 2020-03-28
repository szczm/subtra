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
            int width, height, channels;
            std::shared_ptr<byte> data;
        };

        
        public:

        FileSystem () = default;
        ~FileSystem () = default;

        std::optional<std::string> ReadText (std::string a_path);
        std::optional<TextureData> ReadTexture (std::string a_path);
    };
}