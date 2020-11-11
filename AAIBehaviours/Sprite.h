#pragma once

#include <array>

#include "Structs.h"

class Sprite
{
public:
	Vec<float> position = {};
	Vec<float> scale = {};
	float angle = 0.0f;

	Sprite();
	Sprite(const Vec<float>& position, float angle = 0.0f);
	Sprite(const Vec<float>& position, const Vec<float>& scale, float angle = 0.0f);
	~Sprite() {}

	const Matrix<float> GetTransform() const;

	const std::array<float, 8> GetVertices() const;

	const std::array<unsigned int, 6> GetIndices() const;

private:

	std::array<float, 8> vertices = {
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 1.0f,
			0.5f, 0.5f,
	};

	std::array<unsigned int, 6> indices = { 0, 1, 3, 0, 2, 3 };
};
