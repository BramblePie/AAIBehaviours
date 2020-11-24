#include "FleeBehaviour.h"
#include "Agent.h"

glm::dvec2 FleeBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 d = agent.position - agent.target;
	if (d.x != 0.0 && d.y != 0.0)
		d = glm::normalize(d);
	glm::dvec2 dV = d * agent.maxSpeed;
	return dV - agent.velocity;
}
