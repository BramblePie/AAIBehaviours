#include "Agent.h"

void Agent::ProcessBehaviour(const float delta)
{
	auto f = behaviour->CalculateBehaviour(*this);
	auto accel = f / mass;
	velocity += accel * delta;
	velocity.truncate(maxSpeed);
	position += velocity * delta;
	printf("v = %f, %f\n", velocity.x, velocity.y);
}

void Agent::OnMovement(const int x, const int y)
{
	//printf("OnMovement {%d, %d}\n", x, y);
}

void Agent::OnAction(const int button, const int action, const int mod, const int x, const int y)
{
	//printf("OnAction %d, %d %c : {%d, %d}\n", button, mod, action ? 'P' : 'R', x, y);
	target = Vec<double>(x, y);
	printf("Target set to { %d, %d}", x, x);
}
