#include "Agent.h"

void Agent::ProcessBehaviour(const double delta)
{
	auto f = behaviour->CalculateBehaviour(*this);
	auto accel = f / mass;
	velocity += accel * delta;
	if (double sp = glm::length(velocity); sp > maxSpeed)
		velocity = (velocity / sp) * maxSpeed;

	position += velocity * delta;
	printf("v = %f, %f\n", velocity.x, velocity.y);

	heading = glm::normalize(velocity);
}

void Agent::OnMovement(const int x, const int y)
{
	//printf("OnMovement {%d, %d}\n", x, y);
}

void Agent::OnAction(const int button, const int action, const int mod, const int x, const int y)
{
	//printf("OnAction %d, %d %c : {%d, %d}\n", button, mod, action ? 'P' : 'R', x, y);
	target = glm::dvec2(x, y);
	printf("Target set to { %d, %d}\n", x, x);
}
