#pragma once

#include "Structs.h"

class Agent;

class IBehaviour
{
public:
	/// <summary>
	/// Calculate progression of behaviour
	/// </summary>
	/// <returns>Desired speed</returns>
	virtual Vec<float> CalculateBehaviour(const Agent& agent) = 0;
};
