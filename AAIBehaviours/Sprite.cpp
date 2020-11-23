#include "Sprite.h"

#include <iostream>

Sprite::Sprite()
{
}

Sprite::Sprite(const Vec<double>& position, double angle = 0.0f)
	: position(position), angle(angle)
{
}

Sprite::Sprite(const Vec<double>& position, const Vec<float>& scale, double angle = 0.0)
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
