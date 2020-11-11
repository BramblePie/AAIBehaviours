#pragma once

#include "Structs.h"

class Shader
{
public:
	static constexpr unsigned int pos_attrib_location = 0;
	static constexpr unsigned int color_attrib_location = 1;
	static constexpr unsigned int M_uni_location = 0;

	// Shader program id
	unsigned int ID;

	Shader(const int width, const int height);
	Shader(const Shader& s) = delete;
	~Shader();

	void use() const;

	void SetTransform(const Matrix<float>& m) const;

private:

	static constexpr const char* vertexCode = "#version 430 core\n"
		"layout(location = 0) in vec2 aPos;\n"
		//"layout(location = 1) in vec3 color;\n"
		"layout(location = 0) uniform mat3 M;\n"
		"mat3 VP = mat3("
		"%f, 0.0, 0.0, "
		"0.0, %f, 0.0, "
		"%f, %f, %f );\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(VP * M * vec3(aPos, 1.0), 1.0);\n"
		"}\n";

	static constexpr const char* fragmentCode = "#version 430 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\n";
};
