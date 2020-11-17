#include "MouseObservable.h"

#include <iostream>

MouseObservalbe::MouseObservalbe(GLFWwindow* observing)
	: observing(observing)
{
	// Set user pointer to this instance of KeyBinding
	glfwSetWindowUserPointer(observing, this);

	glfwSetCursorPosCallback(observing,
		[](GLFWwindow* target, const double xpos, const double ypos) {
			static_cast<MouseObservalbe*>(glfwGetWindowUserPointer(target))
				->pos_callback(target, (int)xpos, (int)ypos);
		});

	glfwSetMouseButtonCallback(observing,
		[](GLFWwindow* target, const int button, const int action, const int mod) {
			static_cast<MouseObservalbe*>(glfwGetWindowUserPointer(target))
				->button_callback(target, button, action, mod);
		});
}

void MouseObservalbe::pos_callback(GLFWwindow* target, const int xpos, const int ypos)
{
	for (auto ob : observers)
		ob->OnMovement(xpos, ypos);
}

void MouseObservalbe::button_callback(GLFWwindow* target, const int button, const int action, const int mod)
{
	double x, y;
	glfwGetCursorPos(target, &x, &y);
	for (auto ob : observers)
		ob->OnAction(button, action, mod, x, y);
}
