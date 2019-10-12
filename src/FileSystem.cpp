// SUBTRA FileSystem class header
// 2019 Matthias Scherba @szczm_

#include "FileSystem.hpp"

std::optional<std::string> SUBTRA::FileSystem::readFile(const std::string& a_path) const
{
    // Experimental because GCC 7 :(
    using std::experimental::filesystem::file_size;

    // No value if file could not be open
    std::optional<std::string> opt;

    if (std::ifstream stream{a_path}; stream.good())
    {
        auto filesize = file_size(a_path.c_str());

        std::string content(filesize, '\0');
        stream.read(content.data(), filesize);

        opt = content;
    }

    return opt;
}