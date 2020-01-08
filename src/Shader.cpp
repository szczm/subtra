// SUBTRA Shader class source
// 2019 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <string>
#include <vector>

#include "FileSystem.hpp"
#include "Log.hpp"


SUBTRA::Shader::Shader(const std::string& a_vertexPath, const std::string& a_fragmentPath)
{
    FileSystem fileSystem;

    SUBTRA::Log::Print("Compiling shader program: ");

    GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

    auto vertexSource = fileSystem.ReadText(a_vertexPath);

    if (vertexSource)
    {
        const char* vertexCstr = vertexSource->c_str();

        SUBTRA::Log::Print("Compiling vertex shader: ", a_vertexPath);
        glShaderSource(vertexId, 1, &vertexCstr, nullptr);
        glCompileShader(vertexId);

        Shader::LogErrors(vertexId);
    }
    else
    {
        SUBTRA::Log::Error("Could not open vertex shader file: ", a_vertexPath);
        return;
    }

    auto fragmentSource = fileSystem.ReadText(a_fragmentPath);

    if (fragmentSource)
    {
        const char* fragmentCstr = fragmentSource->c_str();

        SUBTRA::Log::Print("Compiling fragment shader: ", a_fragmentPath);
        glShaderSource(fragmentId, 1, &fragmentCstr, nullptr);
        glCompileShader(fragmentId);

        Shader::LogErrors(fragmentId);
    }
    else
    {
        SUBTRA::Log::Error("Could not open fragment shader file: ", a_fragmentPath);
        return;
    }

    SUBTRA::Log::Print("Linking program");
    m_programId = glCreateProgram();
    glAttachShader(m_programId, vertexId);
    glAttachShader(m_programId, fragmentId);
    glLinkProgram(m_programId);

    int infoLogLength;
    glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &infoLogLength);
    
    if (infoLogLength > 0)
    {
        std::vector<char> programErrorMessage (infoLogLength + 1);
        glGetProgramInfoLog(m_programId, infoLogLength, nullptr, &programErrorMessage[0]);
        SUBTRA::Log::Error(&programErrorMessage[0]);
    }
    
    glDetachShader(m_programId, vertexId);
    glDetachShader(m_programId, fragmentId);
    
    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
}

void SUBTRA::Shader::Use()
{
    glUseProgram(m_programId);
}

GLint SUBTRA::Shader::GetUniformLocation(const std::string& a_key)
{
    return glGetUniformLocation(m_programId, a_key.c_str());
}

void SUBTRA::Shader::Send(const std::string& a_key, int a_value)
{
    glUniform1i(GetUniformLocation(a_key), a_value);
}

void SUBTRA::Shader::Send(const std::string& a_key, float a_value)
{
    glUniform1f(GetUniformLocation(a_key), a_value);
}

void SUBTRA::Shader::LogErrors(GLuint a_shaderId)
{
    int infoLogLength;
    glGetShaderiv(a_shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

    if (infoLogLength > 0)
    {
        std::vector<char> shaderErrorMessage (infoLogLength + 1);
        glGetShaderInfoLog(a_shaderId, infoLogLength, nullptr, &shaderErrorMessage[0]);
        SUBTRA::Log::Error(&shaderErrorMessage[0]);
    }
}