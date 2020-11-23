#pragma once

#include "Sprite.h"
#include "IMouseObserver.h"
#include "IBehaviour.h"
#include "SeekBehaviour.h"

class Agent : public Sprite, public IMouseObserver
{
public:
	IBehaviour* behaviour;

	Vec<double> velocity = {};
	Vec<double> heading = {};
	Vec<double> right = {};
	double mass = 1.0;
	double maxSpeed = 200.0;
	double maxTurn = 0.1;
	Vec<double> target = {};

	Agent() : Sprite({ 0.0,0.0 }, { 100.0f,100.0f }, 0.0), behaviour(new SeekBehaviour())
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

	void ProcessBehaviour(const float delta);

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
