#pragma once

#include "DrawableEntity.h"
#include "BaseAgent.h"
#include "IMouseObserver.h"

class Agent : public BaseAgent, public DrawableEntity, public IMouseObserver
{
public:

	Agent(IBehaviour* behaviour);
	Agent(IBehaviour* behaviour, const IEntity* prey);

	virtual ~Agent()
	{
		delete behaviour;
	}

	// Inherited via BaseAgent

	virtual void ProcessBehaviour(const double delta) override;

private:

	// Inherited via IMouseObserver
	virtual void OnMovement(const int x, const int y) override;
	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) override;
};
