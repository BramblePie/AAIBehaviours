#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

Shader::Shader(const int width, const int height)
{
	// Hard code simple projection to pixels
	float M1[]{ 1.0f, 0.0f, 0.0f, 0.0f }, M2[]{ 0.0f, 1.0f, 0.0f, 0.0f },
		M3[]{ 0.0f, 0.0f, 1.0f, 0.0f }, M4[]{ 0.0f, 0.0f, 0.0f, 1.0f };
	float* M[]{ M1, M2, M3, M4 };

	float right = width;
	float left = 0.0f;
	float top = 0.0f;
	float bottom = height;

	M[0][0] = 2.0f / (right - left);
	M[1][1] = 2.0f / (top - bottom);
	M[2][2] = -1.0f;
	M[3][0] = -(right + left) / (right - left);
	M[3][1] = -(top + bottom) / (top - bottom);

	// Shader code in std string
	const size_t n = 400;
	const char vertexCode[] = "#version 430 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"mat4 M = mat4("
		"%f, 0.0, 0.0, 0.0, "
		"0.0, %f, 0.0, 0.0, "
		"0.0, 0.0, %f, 0.0, "
		"%f, %f, 0.0, 1.0);\n"
		"void main()\n"
		"{\n"
		"	gl_Position = M * vec4(aPos, 1.0);\n"
		"}\n";

	char* vShaderCode = new char[n]();
	sprintf_s(vShaderCode, n, vertexCode, M[0][0], M[1][1], M[2][2], M[3][0], M[3][1]);

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
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::use() const
{
	glUseProgram(ID);
}