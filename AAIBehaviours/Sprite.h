#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "IEntity.h"

class Sprite : public IEntity
{
public:
	glm::dvec2 position = {};
	glm::vec2 scale = {};
	double angle = 0.0;

	Sprite();
	Sprite(const glm::dvec2 position, double angle = 0.0);
	Sprite(const glm::dvec2 position, const glm::vec2 scale, double angle = 0.0);
	virtual ~Sprite() {}

	const glm::mat4 GetTransform() const;

	inline const std::vector<float>& GetVertices() const { return vertices; }

	inline const std::vector<unsigned int>& GetIndices() const { return indices; }

	// Inherited via IEntity

	virtual bool IsDrawable() const override { return true; }
	virtual bool HasController() const override { return false; }
protected:

	void SetVertices(std::initializer_list<float> list);
	void SetIndices(std::initializer_list<unsigned int> list);

private:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
};
