#include "FleeBehaviour.h"
#include "Agent.h"

Vec<double> FleeBehaviour::CalculateBehaviour(const Agent& agent)
{
	Vec<double> dV = (agent.position - agent.target).normalized() * agent.maxSpeed;
	return dV - agent.velocity;
}
