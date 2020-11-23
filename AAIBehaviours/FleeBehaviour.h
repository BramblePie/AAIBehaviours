#pragma once

#include "IBehaviour.h"

class FleeBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual Vec<double> CalculateBehaviour(const Agent& agent) override;
};
