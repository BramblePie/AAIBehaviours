#include "Behaviours.h"

#include "Agent.h"

glm::dvec2 SeekBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 d = agent.target - agent.position;
	if (d.x != 0.0 && d.y != 0.0)
		d = glm::normalize(d);

	const glm::dvec2 dV = d * agent.maxSpeed;
	return dV - agent.velocity;
}

glm::dvec2 FleeBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 d = agent.position - agent.target;
	if (d.x != 0.0 && d.y != 0.0)
		d = glm::normalize(d);

	const glm::dvec2 dV = d * agent.maxSpeed;
	return dV - agent.velocity;
}

glm::dvec2 ArriveBehaviour::CalculateBehaviour(const Agent& agent)
{
	glm::dvec2 d = agent.target - agent.position;
	const double dist = glm::length(d);

	if (dist > 0.0)
	{
		const double tweak = 1.2;
		const double speed = glm::min(dist / ((double)agent.deceleration * tweak), agent.maxSpeed);
		return (d * speed / dist) - agent.velocity;
	}

	return glm::dvec2();
}

glm::dvec2 PursuitBehaviour::CalculateBehaviour(const Agent& agent)
{
	return glm::dvec2();
}