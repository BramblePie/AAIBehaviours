#include "MouseObservable.h"

#include <iostream>

MouseObservable::MouseObservable(GLFWwindow* observing)
{
	// Set user pointer to this instance of KeyBinding
	glfwSetWindowUserPointer(observing, this);

	glfwSetCursorPosCallback(observing,
		[](GLFWwindow* target, const double xpos, const double ypos) {
			static_cast<MouseObservable*>(glfwGetWindowUserPointer(target))
				->pos_callback(target, (int)xpos, (int)ypos);
		});

	glfwSetMouseButtonCallback(observing,
		[](GLFWwindow* target, const int button, const int action, const int mod) {
			static_cast<MouseObservable*>(glfwGetWindowUserPointer(target))
				->button_callback(target, button, action, mod);
		});
}

void MouseObservable::pos_callback(GLFWwindow* target, const int xpos, const int ypos)
{
	for (auto ob : observers)
		ob->OnMovement(xpos, ypos);
}

void MouseObservable::button_callback(GLFWwindow* target, const int button, const int action, const int mod)
{
	double x, y;
	glfwGetCursorPos(target, &x, &y);
	for (auto ob : observers)
		ob->OnAction(button, action, mod, x, y);
}
