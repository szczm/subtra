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
    class FileSystem final
    {
        
    public:

        std::optional<std::string> LoadText (const std::string& PathToFile);
    };
}