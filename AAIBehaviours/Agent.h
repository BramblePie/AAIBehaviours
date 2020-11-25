#pragma once

#include "Sprite.h"
#include "IMouseObserver.h"
#include "Behaviours.h"

class Agent : public Sprite, public IMouseObserver
{
public:
	IBehaviour* behaviour;

	glm::dvec2 velocity = {};
	glm::dvec2 heading = {};
	glm::dvec2 right = {};
	double mass = 1.0;
	double maxSpeed = 200.0;
	double maxTurn = 0.1;
	glm::dvec2 target = {};

	Agent() : Sprite({ 1.0,1.0 }, glm::vec2(100.0)), behaviour(new SeekBehaviour())
	{
	}

	virtual ~Agent()
	{
		delete behaviour;
	}

	void ProcessBehaviour(const double delta);

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
