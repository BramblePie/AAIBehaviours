#pragma once

class IEntity
{
public:

	virtual bool IsDrawable() const = 0;
	virtual bool HasController() const = 0;
private:
};
