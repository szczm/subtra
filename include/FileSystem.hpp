// SUBTRA FileSystem class header
// 2019 Matthias Scherba @szczm_

#pragma once

// #include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include <optional>
#include <string>

namespace SUBTRA
{
    class FileSystem
    {
        public:

        FileSystem() = default;
        ~FileSystem() = default;

        std::optional<std::string> readFile(const std::string& a_path) const;
    };
}