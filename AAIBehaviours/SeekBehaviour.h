#pragma once

#include "IBehaviour.h"

class SeekBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual glm::dvec2 CalculateBehaviour(const Agent& agent) override;
};
