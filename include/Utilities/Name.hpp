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
        constexpr std::size_t hash_string(char const* s, std::size_t count)
        {
            return ((count ? hash_string(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u;
        }
    }

    inline constexpr decltype(auto) operator"" _name(const char* a_name, std::size_t a_length)
    {
        if constexpr (Settings::IS_PLAY_MODE)
        {
            return hash_string(a_name, a_length);
        }
        else
        {
            return a_name;
        }
    }

    using Name = decltype(""_name);
}