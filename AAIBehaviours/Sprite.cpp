#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(float position[2], float angle)
	: angle(angle)
{
	this->position[0] = position[0];
	this->position[1] = position[1];
}

Sprite::Sprite(float position[2], float scale[2], float angle)
	: angle(angle)
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->scale[0] = scale[0];
	this->scale[1] = scale[1];
}

const Matrix<float> Sprite::GetTransform() const
{
	return Matrix<float>();
}
