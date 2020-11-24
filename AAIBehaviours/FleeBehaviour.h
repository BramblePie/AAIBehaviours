#pragma once

#include "IBehaviour.h"

class FleeBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const Agent& agent) override;
};
