#pragma once

#include "IBehaviour.h"

class SeekBehaviour : public IBehaviour
{
public:

private:

	// Inherited via IBehaviour
	virtual Vec<double> CalculateBehaviour(const Agent& agent) override;
};
