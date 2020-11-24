#include "Sprite.h"

#include <iostream>

#include <glm/ext/matrix_transform.hpp>

Sprite::Sprite()
{
}

Sprite::Sprite(const glm::dvec2 position, double angle = 0.0f)
	: position(position), angle(angle)
{
}

Sprite::Sprite(const glm::dvec2 position, const glm::vec2 scale, double angle = 0.0)
	: position(position), scale(scale), angle(angle)
{
}

const glm::mat4 Sprite::GetTransform() const
{
	glm::mat4 r = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 1.0f));
	r = glm::scale(r, glm::vec3(scale.x, scale.y, 1.0f));
	r = glm::rotate(r, (float)angle, glm::vec3(0.0f, 0.0f, 1.0f));

	return r;
}
