#pragma once

#include "Sprite.h"
#include "IMouseObserver.h"

class Agent : public Sprite, public IMouseObserver
{
public:
	Agent() : Sprite({ 0.0f,0.0f }, { 100.0f,100.0f })
	{
	}
	virtual ~Agent() {}

	virtual const std::initializer_list<float>& GetVertices() const
	{
		static const std::initializer_list<float> vertices = {
			0.0f, 0.0f,
			-0.25f, 0.7f,
			0.25f, 0.7f,
			0.0f, 0.1f,
		};

		return vertices;
	}

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
