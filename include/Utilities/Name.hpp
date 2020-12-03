// SUBTRA Name class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include <cstring>
#include <cstdlib>
#include <type_traits>

#include "Settings.hpp"


namespace SUBTRA
{
    // constexpr FNV-1a 32bit hashing algorithm.
    // Stolen from here: https://gist.github.com/Lee-R/3839813
    namespace
    {
        constexpr std::size_t hash_string(char const* String, std::size_t StringLength)
        {
            return ((StringLength ? hash_string(String, StringLength - 1) : 2166136261u) ^ String[StringLength]) * 16777619u;
        }
    }
    // Above is an anonymous namespace: the hash_string function gets a unique name and is not available elsewhere.

    // "Hello"_name is a string in Edit Mode, and becomes a hash in Play Mode. Begone, defines.
    inline constexpr decltype(auto) operator"" _Name(const char* Name, std::size_t NameLength)
    {
        if constexpr (Settings::IsPlayMode)
        {
            return hash_string(Name, NameLength);
        }
        else
        {
            return Name;
        }
    }

    using Name = decltype(""_Name);
}