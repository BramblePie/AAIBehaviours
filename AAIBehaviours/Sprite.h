#pragma once

#include <vector>

#include <glm/glm.hpp>

class Sprite
{
public:
	glm::dvec2 position = {};
	glm::vec2 scale = {};
	double angle = 0.0f;

	Sprite();
	Sprite(const glm::dvec2 position, double angle);
	Sprite(const glm::dvec2 position, const glm::vec2 scale, double angle);
	virtual ~Sprite() {}

	const glm::mat4 GetTransform() const;

	virtual const std::initializer_list<float>& GetVertices() const {
		static const std::initializer_list<float> vertices = {
			0.0f, 0.0f,
			-0.25f, 0.5f,
			0.25f, 0.5f,
			0.0f, 0.3f,
		};

		return vertices;
	}

	virtual const std::initializer_list<unsigned int>& GetIndices() const {
		static const std::initializer_list<unsigned int> indices = { 0, 1, 3, 0, 2, 3 };
		return indices;
	}

private:
};
