#include "Behaviours.h"

#include "Agent.h"

glm::dvec2 SeekBehaviour::CalculateBehaviour(const BaseAgent& agent)
{
	glm::dvec2 d = agent.target - agent.GetPosition();
	if (d.x != 0.0 && d.y != 0.0)
		d = glm::normalize(d);

	const glm::dvec2 dV = d * agent.GetMaxSpeed();
	return dV - agent.GetVelocity();
}

glm::dvec2 FleeBehaviour::CalculateBehaviour(const BaseAgent& agent)
{
	glm::dvec2 d = agent.GetPosition() - agent.target;
	if (d.x != 0.0 && d.y != 0.0)
		d = glm::normalize(d);

	const glm::dvec2 dV = d * agent.GetMaxSpeed();
	return dV - agent.GetVelocity();
}

glm::dvec2 ArriveBehaviour::CalculateBehaviour(const BaseAgent& agent)
{
	glm::dvec2 d = agent.target - agent.GetPosition();
	const double dist = glm::length(d);

	if (dist > 0.0)
	{
		const double tweak = 1.2;
		const double speed = glm::min(dist / ((double)agent.deceleration * tweak), agent.GetMaxSpeed());
		return (d * speed / dist) - agent.GetVelocity();
	}

	return glm::dvec2();
}

glm::dvec2 PursuitBehaviour::CalculateBehaviour(const BaseAgent& agent)
{
	return glm::dvec2();
}
