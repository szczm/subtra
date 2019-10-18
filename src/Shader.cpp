// SUBTRA Shader class source
// 2019 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <string>
#include <string_view>
#include <vector>

#include "FileSystem.hpp"
#include "Log.hpp"

SUBTRA::Shader::Shader(const std::string& a_vertexPath, const std::string& a_fragmentPath)
{
	using namespace std::literals;

	FileSystem fileSystem;

    SUBTRA::Log::Print("Compiling shader program: "sv);

    GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

	int infoLogLength;

	auto vertexSource = fileSystem.readFile(a_vertexPath);

	if (vertexSource)
	{
		const char* vertexCstr = vertexSource->c_str();

		SUBTRA::Log::Print("Compiling vertex shader: "sv, a_vertexPath);
		glShaderSource(vertexID, 1, &vertexCstr, nullptr);
		glCompileShader(vertexID);

		glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0)
		{
			std::vector<char> shaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(vertexID, infoLogLength, nullptr, &shaderErrorMessage[0]);
			SUBTRA::Log::Error(&shaderErrorMessage[0]);
		}
	}
	else
	{
		SUBTRA::Log::Error("Could not open vertex shader file: "sv, a_vertexPath);
		return;
	}

	auto fragmentSource = fileSystem.readFile(a_fragmentPath);

	if (fragmentSource)
	{
		const char* fragmentCstr = fragmentSource->c_str();

		SUBTRA::Log::Print("Compiling fragment shader: "sv, a_fragmentPath);
		glShaderSource(fragmentID, 1, &fragmentCstr, nullptr);
		glCompileShader(fragmentID);

		glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0)
		{
			std::vector<char> shaderErrorMessage(infoLogLength + 1);
			glGetShaderInfoLog(fragmentID, infoLogLength, nullptr, &shaderErrorMessage[0]);
			SUBTRA::Log::Error(&shaderErrorMessage[0]);
		}
	}
	else
	{
		SUBTRA::Log::Error("Could not open fragment shader file: "sv, a_fragmentPath);
		return;
	}

	SUBTRA::Log::Print("Linking program"sv);
	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexID);
	glAttachShader(m_programID, fragmentID);
	glLinkProgram(m_programID);

	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	
    if (infoLogLength > 0)
    {
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(m_programID, infoLogLength, nullptr, &programErrorMessage[0]);
		SUBTRA::Log::Error(&programErrorMessage[0]);
	}
	
	glDetachShader(m_programID, vertexID);
	glDetachShader(m_programID, fragmentID);
	
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

void SUBTRA::Shader::use()
{
    glUseProgram(m_programID);
}