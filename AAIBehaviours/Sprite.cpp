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
	r = transform::rotate(r, (float)-PI / 2.0f);

	return r;
}

const std::vector<float>& Sprite::GetVertices() const
{
	return vertices;
}

const std::vector<unsigned int>& Sprite::GetIndices() const
{
	return indices;
}

void Sprite::OnMovement(const int x, const int y)
{
	//printf("OnMovement {%d, %d}\n", x, y);
}

void Sprite::OnAction(const int button, const int action, const int mod, const int x, const int y)
{
	printf("OnAction %d, %d %c : {%d, %d}\n", button, mod, action ? 'P' : 'R', x, y);
}
