#include "Agent.h"

#include <glm/gtx/vector_angle.hpp>

Agent::Agent(IBehaviour* behaviour)
	: Agent(behaviour, nullptr)
{
}

Agent::Agent(IBehaviour* behaviour, Sprite* prey)
	: Sprite({ 0.0,0.0 }, glm::vec2(100.0)), behaviour(behaviour), prey(prey)
{
}

void Agent::ProcessBehaviour(const double delta)
{
	auto force = behaviour->CalculateBehaviour(*this);
	force = glm::min(force, glm::normalize(force) * maxForce);

	auto accel = force / mass;
	velocity += accel * delta;

	double sp = glm::length(velocity);
	if (sp > maxSpeed)
		velocity = glm::normalize(velocity) * maxSpeed;

	position += velocity * delta;

	if (sp > 0.0)
	{
		heading = glm::normalize(velocity);
		angle = glm::orientedAngle(glm::dvec2(0.0, -1.0), heading);
	}
}

void Agent::OnMovement(const int x, const int y)
{
	//printf("OnMovement {%d, %d}\n", x, y);
}

void Agent::OnAction(const int button, const int action, const int mod, const int x, const int y)
{
	//printf("OnAction %d, %d %c : {%d, %d}\n", button, mod, action ? 'P' : 'R', x, y);
	target = glm::dvec2(x, y);
	if (action)
		printf("Target(0x%p) set to { %d, %d }\n", this, x, y);
}