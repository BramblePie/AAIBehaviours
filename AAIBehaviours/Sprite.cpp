#include "Sprite.h"

#include <iostream>

Sprite::Sprite()
{
}

Sprite::Sprite(const Vec<float>& position, float angle)
	: position(position), angle(angle)
{
}

Sprite::Sprite(const Vec<float>& position, const Vec<float>& scale, float angle)
	: position(position), scale(scale), angle(angle)
{
}

const Matrix<float> Sprite::GetTransform() const
{
	Matrix<float> r = {};
	r = transform::translate(r, position);
	r = transform::scale(r, scale);
	r = transform::rotate(r, angle);

	return r;
}
