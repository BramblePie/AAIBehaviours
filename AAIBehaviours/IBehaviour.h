#pragma once

#include <glm/vec2.hpp>

class Agent;

class IBehaviour
{
public:
	/// <summary>
	/// Calculate progression of behaviour
	/// </summary>
	/// <returns>Desired speed</returns>
	virtual glm::dvec2 CalculateBehaviour(const Agent& agent) = 0;
};
