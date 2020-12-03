// SUBTRA Shader class source
// 2020 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <string>
#include <vector>

#include "FileSystem.hpp"
#include "Log.hpp"


SUBTRA::Shader SUBTRA::Shader::LoadFromFile (const std::string& PathToVertexShaderFile, const std::string& PathToFragmentShaderFile)
{
    FileSystem FileSystem;

    SUBTRA::Log::Print("Compiling shader program: ");

    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    auto VertexShaderSource = FileSystem.LoadText(PathToVertexShaderFile);

    if (VertexShaderSource)
    {
        const char* CString = VertexShaderSource->c_str();

        Log::Print("Compiling vertex shader: ", PathToVertexShaderFile);

        glShaderSource(VertexShaderID, 1, &CString, nullptr);
        glCompileShader(VertexShaderID);

        LogShaderErrors(VertexShaderID);
    }
    else
    {
        Log::Error("Could not open vertex shader file: ", PathToVertexShaderFile);

        return {};
    }

    auto FragmentShaderSource = FileSystem.LoadText(PathToFragmentShaderFile);

    if (FragmentShaderSource)
    {
        const char* fragmentCstr = FragmentShaderSource->c_str();

        Log::Print("Compiling fragment shader: ", PathToFragmentShaderFile);
        
        glShaderSource(FragmentShaderID, 1, &fragmentCstr, nullptr);
        glCompileShader(FragmentShaderID);

        LogShaderErrors(FragmentShaderID);
    }
    else
    {
        Log::Error("Could not open fragment shader file: ", PathToFragmentShaderFile);

        return {};
    }

    Log::Print("Linking program");

    Shader ShaderProgram;

    ShaderProgram.ProgramID = glCreateProgram();
    glAttachShader(ShaderProgram.ProgramID, VertexShaderID);
    glAttachShader(ShaderProgram.ProgramID, FragmentShaderID);
    glLinkProgram(ShaderProgram.ProgramID);

    int InfoLogLength;
    glGetProgramiv(ShaderProgram.ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    
    if (InfoLogLength > 0)
    {
        std::vector<char> ProgramErrorMessage (InfoLogLength + 1);
        glGetProgramInfoLog(ShaderProgram.ProgramID, InfoLogLength, nullptr, &ProgramErrorMessage[0]);

        Log::Error(&ProgramErrorMessage[0]);
    }
    
    glDetachShader(ShaderProgram.ProgramID, VertexShaderID);
    glDetachShader(ShaderProgram.ProgramID, FragmentShaderID);
    
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ShaderProgram;
}

void SUBTRA::Shader::Use ()
{
    glUseProgram(ProgramID);
}

GLint SUBTRA::Shader::GetUniformLocation (const std::string& Name)
{
    return glGetUniformLocation(ProgramID, Name.c_str());
}

void SUBTRA::Shader::Send (const std::string& Name, int Value)
{
    glUniform1i(GetUniformLocation(Name), Value);
}

void SUBTRA::Shader::Send (const std::string& Name, float Value)
{
    glUniform1f(GetUniformLocation(Name), Value);
}

void SUBTRA::Shader::Send (const std::string& Name, glm::mat4 Value)
{
    glUniformMatrix4fv(GetUniformLocation(Name), 1, GL_FALSE, glm::value_ptr(Value));
}

void SUBTRA::Shader::Send (const std::string& Name, Color Value, ColorMode ColorMode)
{
    switch (ColorMode)
    {
        case ColorMode::RGB:
        {
            glUniform3f(GetUniformLocation(Name), Value.Red, Value.Green, Value.Blue);
            break;
        }

        case ColorMode::RGBA:
        {
            glUniform4f(GetUniformLocation(Name), Value.Red, Value.Green, Value.Blue, Value.Alpha);
            break;
        }
    }
}

void SUBTRA::Shader::LogShaderErrors (GLuint ShaderID)
{
    int InfoLogLength;
    glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        std::vector<char> ShaderErrorMessage (InfoLogLength + 1);
        glGetShaderInfoLog(ShaderID, InfoLogLength, nullptr, &ShaderErrorMessage[0]);
        
        Log::Error(&ShaderErrorMessage[0]);
    }
}