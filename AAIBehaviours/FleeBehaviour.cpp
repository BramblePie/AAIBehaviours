#include "FleeBehaviour.h"
#include "Agent.h"

glm::dvec2 FleeBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 dV = glm::normalize(agent.position - agent.target) * agent.maxSpeed;
	return dV - agent.velocity;
}
