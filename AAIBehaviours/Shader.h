#pragma once

#include <glm/mat4x4.hpp>

class Shader
{
public:
	static constexpr unsigned int pos_attrib_location = 0;
	static constexpr unsigned int color_attrib_location = 1;
	static constexpr unsigned int M_uni_location = 0;
	static constexpr unsigned int PV_uni_location = 1;

	// Shader program id
	unsigned int ID;

	Shader(const int width, const int height);
	Shader(const Shader& s) = delete;
	~Shader();

	void use() const;

	void SetTransform(const glm::mat4& m) const;

private:

	static constexpr const char* vertexCode = "#version 430 core\n"
		"layout(location = 0) in vec2 aPos;\n"
		//"layout(location = 1) in vec3 color;\n"
		"layout(location = 0) uniform mat4 M;\n"
		"layout(location = 1) uniform mat4 VP;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = VP * M * vec4(aPos, 0.0, 1.0);\n"
		"}\n";

	static constexpr const char* fragmentCode = "#version 430 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\n";
};
