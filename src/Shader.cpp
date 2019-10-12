// SUBTRA Shader class source
// 2019 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <string>
#include <string_view>
#include <vector>

#include "Log.hpp"

SUBTRA::Shader::Shader(const std::string& a_vertexPath, const std::string& a_fragmentPath)
{
    init(a_vertexPath, a_fragmentPath);
}

void SUBTRA::Shader::init(const std::string& a_vertexPath, const std::string& a_fragmentPath)
{
	using namespace std::literals;

    SUBTRA::Log::Print("Compiling shader: "sv);

    GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    // TODO: Read from a file
	std::string vertexSource = "#version 330 core\nlayout(location = 0) in vec3 vertexPosition_modelspace;\nvoid main(){  gl_Position.xyz = vertexPosition_modelspace;  gl_Position.w = 1.0;}"s;
	std::string fragmentSource = "#version 330 core\nout vec3 color;void main(){  color = vec3(1,0,0);}"s;

	const char* vertexCstr = vertexSource.c_str();
	const char* fragmentCstr = fragmentSource.c_str();

	int infoLogLength;

	SUBTRA::Log::Print("Compiling vertex shader: "sv, a_vertexPath);
	glShaderSource(vertexID, 1, &vertexCstr, NULL);
	glCompileShader(vertexID);

	glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
    {
		std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		SUBTRA::Log::Error(&vertexShaderErrorMessage[0]);
	}

	SUBTRA::Log::Print("Compiling fragment shader"sv, a_fragmentPath);
	glShaderSource(fragmentID, 1, &fragmentCstr, NULL);
	glCompileShader(fragmentID);

	// Check Fragment Shader
	glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
    {
		std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		SUBTRA::Log::Error(&fragmentShaderErrorMessage[0]);
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
		glGetProgramInfoLog(m_programID, infoLogLength, NULL, &programErrorMessage[0]);
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