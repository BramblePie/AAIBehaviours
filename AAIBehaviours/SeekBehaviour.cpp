#include "SeekBehaviour.h"
#include "Agent.h"

glm::dvec2 SeekBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 dV = glm::normalize(agent.target - agent.position) * agent.maxSpeed;
	return dV - agent.velocity;
}
