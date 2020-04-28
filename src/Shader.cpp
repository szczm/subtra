// SUBTRA Shader class source
// 2020 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <string>
#include <vector>

#include "FileSystem.hpp"
#include "Log.hpp"


SUBTRA::Shader SUBTRA::Shader::LoadFromFile (const std::string& a_vertexPath, const std::string& a_fragmentPath)
{
    FileSystem fileSystem;

    SUBTRA::Log::Print("Compiling shader program: ");

    GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

    auto vertexSource = fileSystem.LoadText(a_vertexPath);

    if (vertexSource)
    {
        const char* vertexCstr = vertexSource->c_str();

        Log::Print("Compiling vertex shader: ", a_vertexPath);

        glShaderSource(vertexId, 1, &vertexCstr, nullptr);
        glCompileShader(vertexId);

        LogShaderErrors(vertexId);
    }
    else
    {
        Log::Error("Could not open vertex shader file: ", a_vertexPath);

        return {};
    }

    auto fragmentSource = fileSystem.LoadText(a_fragmentPath);

    if (fragmentSource)
    {
        const char* fragmentCstr = fragmentSource->c_str();

        Log::Print("Compiling fragment shader: ", a_fragmentPath);
        
        glShaderSource(fragmentId, 1, &fragmentCstr, nullptr);
        glCompileShader(fragmentId);

        LogShaderErrors(fragmentId);
    }
    else
    {
        Log::Error("Could not open fragment shader file: ", a_fragmentPath);

        return {};
    }

    Log::Print("Linking program");

    Shader shader;

    shader.m_programId = glCreateProgram();
    glAttachShader(shader.m_programId, vertexId);
    glAttachShader(shader.m_programId, fragmentId);
    glLinkProgram(shader.m_programId);

    int infoLogLength;
    glGetProgramiv(shader.m_programId, GL_INFO_LOG_LENGTH, &infoLogLength);
    
    if (infoLogLength > 0)
    {
        std::vector<char> programErrorMessage (infoLogLength + 1);
        glGetProgramInfoLog(shader.m_programId, infoLogLength, nullptr, &programErrorMessage[0]);

        Log::Error(&programErrorMessage[0]);
    }
    
    glDetachShader(shader.m_programId, vertexId);
    glDetachShader(shader.m_programId, fragmentId);
    
    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

    return shader;
}

void SUBTRA::Shader::Use ()
{
    glUseProgram(m_programId);
}

GLint SUBTRA::Shader::GetUniformLocation (const std::string& a_uniformName)
{
    return glGetUniformLocation(m_programId, a_uniformName.c_str());
}

void SUBTRA::Shader::Send (const std::string& a_key, int a_value)
{
    glUniform1i(GetUniformLocation(a_key), a_value);
}

void SUBTRA::Shader::Send (const std::string& a_key, float a_value)
{
    glUniform1f(GetUniformLocation(a_key), a_value);
}

void SUBTRA::Shader::Send (const std::string& a_key, glm::mat4 a_value)
{
    glUniformMatrix4fv(GetUniformLocation(a_key), 1, GL_FALSE, glm::value_ptr(a_value));
}

void SUBTRA::Shader::Send (const std::string& a_key, Color a_value, ColorMode a_colorMode)
{
    switch (a_colorMode)
    {
        case ColorMode::RGB:
        {
            glUniform3f(GetUniformLocation(a_key), a_value.red, a_value.green, a_value.blue);
            break;
        }

        case ColorMode::RGBA:
        {
            glUniform4f(GetUniformLocation(a_key), a_value.red, a_value.green, a_value.blue, a_value.alpha);
            break;
        }
    }
}

void SUBTRA::Shader::LogShaderErrors (GLuint a_shaderId)
{
    int infoLogLength;
    glGetShaderiv(a_shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

    if (infoLogLength > 0)
    {
        std::vector<char> shaderErrorMessage (infoLogLength + 1);
        glGetShaderInfoLog(a_shaderId, infoLogLength, nullptr, &shaderErrorMessage[0]);
        Log::Error(&shaderErrorMessage[0]);
    }
}