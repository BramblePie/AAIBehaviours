#pragma once

#include <vector>

#include "Structs.h"
#include "IMouseObserver.h"

class Sprite : public IMouseObserver
{
public:
	Vec<float> position = {};
	Vec<float> scale = {};
	float angle = 0.0f;

	Sprite();
	Sprite(const Vec<float>& position, float angle = 0.0f);
	Sprite(const Vec<float>& position, const Vec<float>& scale, float angle = 0.0f);
	~Sprite() {}

	const Matrix<float> GetTransform() const;

	const std::vector<float>& GetVertices() const;

	const std::vector<unsigned int>& GetIndices() const;

private:

	std::vector<float> vertices = {
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 1.0f,
			0.5f, 0.5f,
	};

	std::vector<unsigned int> indices = { 0, 1, 3, 0, 2, 3 };

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
