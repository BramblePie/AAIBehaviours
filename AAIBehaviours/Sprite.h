#pragma once

#include "Structs.h"

class Sprite
{
public:
	float position[2] = {};
	float scale[2] = { 1.0f, 1.0f };
	float angle = 0.0f;

	Sprite();
	Sprite(float position[2], float angle = 0.0f);
	Sprite(float position[2], float scale[2], float angle = 0.0f);
	~Sprite() {}

	const Matrix<float> GetTransform() const;

private:

	const float v[8] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.5f, 0.5f,
	};
};
