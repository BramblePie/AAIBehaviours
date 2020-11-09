#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "MouseObserver.h"

class Window : public MouseObserver
{
public:

	Window(const int width, const int height);
	~Window()
	{
		glfwTerminate();
	}

	int Start();

private:

	GLFWwindow* window;

	int width, height;

	GLFWwindow* SetupWindow(const int w, const int h);
};
