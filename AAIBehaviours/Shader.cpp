#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

Shader::Shader(const int width, const int height)
{
	// Hard code simple projection to pixels
	const float right = (float)width;
	const float left = 0.0f;
	const float top = 0.0f;
	const float bottom = (float)height;

	const float m_00 = 2.0f / (right - left);
	const float m_11 = 2.0f / (top - bottom);
	const float m_20 = -(right + left) / (right - left);
	const float m_21 = -(top + bottom) / (top - bottom);
	const float m_22 = -1.0f;

	// Shader code in const chars
	const size_t n = 400;
	const char vertexCode[] = "#version 430 core\n"
		"layout(location = 0) in vec2 aPos;\n"
		"mat3 M = mat3("
		"%f, 0.0, 0.0, "
		"0.0, %f, 0.0, "
		"%f, %f, %f );\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(M * vec3(aPos, 1.0), 1.0);\n"
		"}\n";

	char* vShaderCode = new char[n]();
	sprintf_s(vShaderCode, n, vertexCode, m_00, m_11, m_20, m_21, m_22);

	const char* fShaderCode = "#version 430 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\n";

	// Compile shader
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	// print linking errors if any
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	delete[] vShaderCode;
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::use() const
{
	glUseProgram(ID);
}
