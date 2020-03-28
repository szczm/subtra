// SUBTRA Shader class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "GLCommon.hpp"
#include "GLMCommon.hpp"
#include "Utilities/Color.hpp"

#include <string>

namespace SUBTRA
{
    class Shader
    {
        public:

        Shader (std::string a_vertexPath, std::string a_fragmentPath);
        Shader () = default;
        ~Shader () = default;

        void Use ();


        enum class ColorMode
        {
            RGB,
            RGBA
        };

        void Send (std::string a_key, int a_value);
        void Send (std::string a_key, float a_value);
        void Send (std::string a_key, glm::mat4 a_value);
        void Send (std::string a_key, Color a_value, ColorMode a_colorMode = ColorMode::RGBA);

        GLint GetUniformLocation (std::string a_key);


        private:

        static void LogErrors (GLuint a_shaderId);

        GLuint m_programId = 0;
    };
}