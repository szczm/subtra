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

    GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

	int infoLogLength;

	auto vertexSource = fileSystem.ReadFile(a_vertexPath);

	if (vertexSource)
	{
		const char* vertexCstr = vertexSource->c_str();

		SUBTRA::Log::Print("Compiling vertex shader: "sv, a_vertexPath);
		glShaderSource(vertexId, 1, &vertexCstr, nullptr);
		glCompileShader(vertexId);

		glGetShaderiv(vertexId, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0)
		{
			std::vector<char> shaderErrorMessage (infoLogLength + 1);
			glGetShaderInfoLog(vertexId, infoLogLength, nullptr, &shaderErrorMessage[0]);
			SUBTRA::Log::Error(&shaderErrorMessage[0]);
		}
	}
	else
	{
		SUBTRA::Log::Error("Could not open vertex shader file: "sv, a_vertexPath);
		return;
	}

	auto fragmentSource = fileSystem.ReadFile(a_fragmentPath);

	if (fragmentSource)
	{
		const char* fragmentCstr = fragmentSource->c_str();

		SUBTRA::Log::Print("Compiling fragment shader: "sv, a_fragmentPath);
		glShaderSource(fragmentId, 1, &fragmentCstr, nullptr);
		glCompileShader(fragmentId);

		glGetShaderiv(fragmentId, GL_INFO_LOG_LENGTH, &infoLogLength);

		if (infoLogLength > 0)
		{
			std::vector<char> shaderErrorMessage (infoLogLength + 1);
			glGetShaderInfoLog(fragmentId, infoLogLength, nullptr, &shaderErrorMessage[0]);
			SUBTRA::Log::Error(&shaderErrorMessage[0]);
		}
	}
	else
	{
		SUBTRA::Log::Error("Could not open fragment shader file: "sv, a_fragmentPath);
		return;
	}

	SUBTRA::Log::Print("Linking program"sv);
	m_programId = glCreateProgram();
	glAttachShader(m_programId, vertexId);
	glAttachShader(m_programId, fragmentId);
	glLinkProgram(m_programId);

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