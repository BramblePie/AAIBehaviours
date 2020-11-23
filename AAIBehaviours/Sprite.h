#pragma once

#include <vector>

#include "Structs.h"

class Sprite
{
public:
	Vec<double> position = {};
	Vec<float> scale = {};
	double angle = 0.0f;

	Sprite();
	Sprite(const Vec<double>& position, double angle);
	Sprite(const Vec<double>& position, const Vec<float>& scale, double angle);
	virtual ~Sprite() {}

	const Matrix<float> GetTransform() const;

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
