#pragma once

struct IEntity
{
	virtual virtual const glm::dvec2& GetPosition() const = 0;
	virtual bool HasController() const = 0;
	virtual bool IsDrawable() const = 0;

	virtual ~IEntity() {}
};
