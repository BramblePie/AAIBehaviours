#include "MouseObserver.h"

#include <iostream>

MouseObserver* MouseObserver::singleton = nullptr;

MouseObserver::MouseObserver(GLFWwindow* observing)
	: observing(observing)
{
	singleton = this;

	// Set user pointer to this instance of KeyBinding
	glfwSetWindowUserPointer(observing, this);

	glfwSetCursorPosCallback(observing,
							 [](GLFWwindow* target, const double xpos, const double ypos) {
								 static_cast<MouseObserver*>(glfwGetWindowUserPointer(target))
									 ->pos_callback(target, (int)xpos, (int)ypos);
							 });

	glfwSetMouseButtonCallback(observing,
							   [](GLFWwindow* target, const int button, const int action, const int mod) {
								   static_cast<MouseObserver*>(glfwGetWindowUserPointer(target))
									   ->button_callback(target, button, action, mod);
							   });
}

void MouseObserver::pos_callback(GLFWwindow* target, const int xpos, const int ypos)
{
	//printf("Cursor moved! { %d, %d }\n", xpos, ypos);

	for (auto e : positionEvents)
		e(xpos, ypos);
}

void MouseObserver::button_callback(GLFWwindow* target, const int button, const int action, const int mod)
{
	printf("Mouse button event on : %d\n", button);

	double x, y;
	glfwGetCursorPos(target, &x, &y);
	for (auto e : mouseEvents)
		e(button, action, mod, (int)x, (int)y);
}