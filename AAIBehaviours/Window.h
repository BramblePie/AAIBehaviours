#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
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
};
