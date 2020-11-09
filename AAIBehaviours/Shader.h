#pragma once

class Shader
{
public:
	// Shader program id
	unsigned int ID;

	Shader();
	Shader(const Shader& s) = delete;
	~Shader();

	void use() const;

private:
};