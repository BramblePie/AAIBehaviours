#include "DrawableEntity.h"

#include <iostream>

#include <glm/ext/matrix_transform.hpp>

DrawableEntity::DrawableEntity()
	: DrawableEntity(glm::dvec2(0.0f), glm::vec2(1.0f))
{
}

DrawableEntity::DrawableEntity(const glm::dvec2 position, double angle)
	: DrawableEntity(position, glm::vec2(1.0f), angle)
{
}

DrawableEntity::DrawableEntity(const glm::dvec2 position, const glm::vec2 scale, double angle)
	: pos(position), scale(scale), angle(angle)
{
	vertices.insert(std::begin(vertices), {
						0.0f, 0.0f,
						-0.25f, 0.5f,
						0.25f, 0.5f,
						0.0f, 0.3f
		});
	indices.insert(std::begin(indices), { 0, 1, 3, 0, 2, 3 });
}

const glm::mat4 DrawableEntity::GetTransform() const
{
	glm::mat4 r = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 1.0f));
	r = glm::scale(r, glm::vec3(scale.x, scale.y, 1.0f));
	r = glm::rotate(r, (float)angle, glm::vec3(0.0f, 0.0f, 1.0f));

	return r;
}

void DrawableEntity::SetVertices(std::initializer_list<float> list)
{
	vertices.clear();
	vertices.insert(std::begin(vertices), list);
}

void DrawableEntity::SetIndices(std::initializer_list<unsigned int> list)
{
	indices.clear();
	indices.insert(std::begin(indices), list);
}
