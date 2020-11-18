#pragma once

#include "Sprite.h"
#include "IMouseObserver.h"
#include "IBehaviour.h"
#include "SeekBehaviour.h"

class Agent : public Sprite, public IMouseObserver
{
public:
	IBehaviour* behaviour;

	Agent() : Sprite({ 0.0f,0.0f }, { 100.0f,100.0f }), behaviour(new SeekBehaviour())
	{
	}

	virtual ~Agent()
	{
		delete behaviour;
	}

	virtual const std::initializer_list<float>& GetVertices() const
	{
		static const std::initializer_list<float> vertices = {
			0.0f, 0.0f,
			-0.25f, 0.5f,
			0.25f, 0.5f,
			0.0f, 0.3f,
		};

		return vertices;
	}

	void ProcessBehaviour();

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
