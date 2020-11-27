#pragma once

class MouseObservable;

class IMouseObserver
{
public:
	//IMouseObserver();
	~IMouseObserver() {}

	virtual void OnMovement(const int x, const int y) = 0;

	virtual void OnAction(const int button, const int action, const int mod, const int x, const int y) = 0;

private:
};
