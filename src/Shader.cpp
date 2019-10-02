// SUBTRA Shader class source
// 2019 Matthias Scherba @szczm_

#include "Shader.hpp"

#include <vector>

#include "Log.hpp"

SUBTRA::Shader::Shader() {}
SUBTRA::Shader::~Shader() {}

SUBTRA::Shader::Shader(const char* a_name, const char* a_vertexPath, const char* a_fragmentPath)
 : m_name(a_name)
{
    init(a_name, a_vertexPath, a_fragmentPath);
}

void SUBTRA::Shader::init(const char* a_name, const char* a_vertexPath, const char* a_fragmentPath)
{
    SUBTRA::Log::Print("Compiling shader: ", a_name);

    GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    // TODO: Read from a file
	const char* vertexSource = "#version 330 core\nlayout(location = 0) in vec3 vertexPosition_modelspace;\nvoid main(){  gl_Position.xyz = vertexPosition_modelspace;  gl_Position.w = 1.0;}";
	const char* fragmentSource = "#version 330 core\nout vec3 color;void main(){  color = vec3(1,0,0);}";

	int infoLogLength;

	SUBTRA::Log::Print("Compiling vertex shader");
	glShaderSource(vertexID, 1, &vertexSource, NULL);
	glCompileShader(vertexID);

	glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
    {
		std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		SUBTRA::Log::Error(&vertexShaderErrorMessage[0]);
	}

	SUBTRA::Log::Print("Compiling fragment shader");
	glShaderSource(fragmentID, 1, &fragmentSource, NULL);
	glCompileShader(fragmentID);

	// Check Fragment Shader
	glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
    {
		std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		SUBTRA::Log::Error(&fragmentShaderErrorMessage[0]);
	}

	SUBTRA::Log::Print("Linking program");
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