#pragma once

#include <glm/vec2.hpp>

class BaseAgent;

class IBehaviour
{
public:
	/// <summary>
	/// Calculate progression of behaviour
	/// </summary>
	/// <returns>Desired speed</returns>
	virtual glm::dvec2 CalculateBehaviour(const BaseAgent& agent) = 0;
};
