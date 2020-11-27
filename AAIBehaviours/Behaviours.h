#pragma once

#include "IBehaviour.h"

class SeekBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const BaseAgent& agent) override;
};

class FleeBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const BaseAgent& agent) override;
};

class ArriveBehaviour : public IBehaviour
{
public:
	enum class Deceleration : unsigned char
	{
		fast = 1,
		normal,
		slow
	};

private:

	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const BaseAgent& agent) override;
};

class PursuitBehaviour : public IBehaviour
{
public:
private:
	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const BaseAgent& agent) override;
};
