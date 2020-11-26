#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <set>
#include <functional>

#include "IMouseObserver.h"

class MouseObservable
{
public:
	MouseObservable(const MouseObservable& mo) = delete;
	~MouseObservable()
	{
		observers.clear();
	}

	inline void Subscribe(IMouseObserver* observer) const
	{
		observers.push_back(observer);
	}

protected:
	MouseObservable(GLFWwindow* observing);

private:

	mutable std::vector< IMouseObserver*> observers;

	// Callback function on each cursor movement
	void pos_callback(GLFWwindow* target, const int xpos, const int ypos);

	// Callback function on mouse button events
	void button_callback(GLFWwindow* target, const int button, const int action, const int mod);
};
