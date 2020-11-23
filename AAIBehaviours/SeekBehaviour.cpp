#include "SeekBehaviour.h"
#include "Agent.h"

Vec<double> SeekBehaviour::CalculateBehaviour(const Agent& agent)
{
	Vec<double> dV = (agent.target - agent.position).normalize() * agent.maxSpeed;
	return dV - agent.velocity;
}
