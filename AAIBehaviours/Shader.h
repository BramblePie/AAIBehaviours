#pragma once

class Shader
{
public:
	// Shader program id
	unsigned int ID;

	Shader(const int width, const int height);
	Shader(const Shader& s) = delete;
	~Shader();

	void use() const;

private:
};