#pragma once

#include <glm/vec2.hpp>

#include "IEntity.h"
#include "Behaviours.h"

class BaseAgent : public virtual IEntity
{
public:
	IBehaviour* behaviour;

	// ---- Behaviour context ----

	glm::dvec2 target = glm::dvec2(0.0);
	const IEntity* prey;
	ArriveBehaviour::Deceleration deceleration = ArriveBehaviour::Deceleration::normal;

	BaseAgent(IBehaviour* behaviour, const IEntity* prey,
		glm::dvec2 initPosition,
		glm::dvec2 initVelocity,
		double mass, double maxSpeed, double maxForce)
		: behaviour(behaviour), prey(prey),
		position(initPosition), velocity(initVelocity),
		mass(mass), maxSpeed(maxSpeed), maxForce(maxForce)
	{}
	virtual ~BaseAgent() {}

	virtual void ProcessBehaviour(const double delta) = 0;

	// ---- Inherited via IEntity ----

	bool HasController() const final override { return true; }

	// ---- public getters ----

	virtual const glm::dvec2& GetPosition() const override { return position; }
	virtual const glm::dvec2& GetVelocity() const { return velocity; }
	virtual const double GetAngle() const { return angle; }
	virtual const double GetMass() const { return mass; }
	virtual const double GetMaxSpeed() const { return maxSpeed; }
	virtual const double GetMaxForce() const { return maxForce; }

protected:
	glm::dvec2 position;
	glm::dvec2 velocity;
	glm::dvec2 heading = glm::dvec2(-1.0, 0.0);
	double angle = 0.0;
	double mass;
	double maxSpeed;
	double maxForce;
	//double maxTurn = 0.1;
};
