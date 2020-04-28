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

        // TODO: Implement move func. in case more data is added to class
        static Shader LoadFromFile(const std::string& a_vertexPath, const std::string& a_fragmentPath);

        void Use ();


        enum class ColorMode
        {
            RGB,
            RGBA
        };

        void Send (const std::string& a_key, int a_value);
        void Send (const std::string& a_key, float a_value);
        void Send (const std::string& a_key, glm::mat4 a_value);
        void Send (const std::string& a_key, Color a_value, ColorMode a_colorMode = ColorMode::RGBA);

        GLint GetUniformLocation (const std::string& a_uniformName);


        private:

        static void LogShaderErrors (GLuint a_shaderId);

        GLuint m_programId = 0;
    };
}