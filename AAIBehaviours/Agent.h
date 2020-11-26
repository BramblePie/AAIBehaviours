#pragma once

#include "DrawableEntity.h"
#include "BaseAgent.h"
#include "IMouseObserver.h"
#include "Behaviours.h"

class Agent : public BaseAgent, public IMouseObserver
{
public:
	IBehaviour* behaviour;

	// ---- Behaviour context ----

	glm::dvec2 target = glm::dvec2(0.0);
	IEntity* prey;
	ArriveBehaviour::Deceleration deceleration = ArriveBehaviour::Deceleration::normal;

	Agent(IBehaviour* behaviour);
	Agent(IBehaviour* behaviour, DrawableEntity* prey);

	virtual ~Agent()
	{
		delete behaviour;
	}

	// Inherited via BaseAgent

	virtual bool IsDrawable() const override { return false; }
	virtual void ProcessBehaviour(const double delta) override;

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
