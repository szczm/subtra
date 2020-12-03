// SUBTRA File System class header
// 2020 Matthias Scherba @szczm_

#include "FileSystem.hpp"


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