#include "FleeBehaviour.h"
#include "Agent.h"

Vec<double> FleeBehaviour::CalculateBehaviour(const Agent& agent)
{
	Vec<double> dV = (agent.position - agent.target).normalize() * agent.maxSpeed;
	return dV - agent.velocity;
}
