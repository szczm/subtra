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

        enum class ColorMode
        {
            RGB,
            RGBA
        };

        static Shader LoadFromFile(const std::string& PathToVertexShaderFile, const std::string& PathToFragmentShaderFile);

        void Use ();

        // If a new uniform type is required, add an overload below
        void Send (const std::string& Name, int Value);
        void Send (const std::string& Name, float Value);
        void Send (const std::string& Name, glm::mat4 Value);
        void Send (const std::string& Name, Color Value, ColorMode ColorMode = ColorMode::RGBA);

        GLint GetUniformLocation (const std::string& Name);


    private:

        static void LogShaderErrors (GLuint ShaderID);

        GLuint ProgramID = 0;
    };
}