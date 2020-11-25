#pragma once

#include "Sprite.h"
#include "IMouseObserver.h"
#include "Behaviours.h"

class Agent : public Sprite, public IMouseObserver
{
public:
	IBehaviour* behaviour;

	glm::dvec2 velocity = glm::dvec2(0.0);
	glm::dvec2 heading = glm::dvec2(-1.0, 0.0);
	glm::dvec2 right = glm::dvec2(0.0, 1.0);
	double mass = 1.0;
	double maxSpeed = 200.0;
	double maxTurn = 0.1;

	// Behaviour context

	glm::dvec2 target = glm::dvec2(0.0);
	ArriveBehaviour::Deceleration deceleration = ArriveBehaviour::Deceleration::normal;

	Agent() : Sprite({ 1.0,1.0 }, glm::vec2(100.0)), behaviour(new ArriveBehaviour())
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
