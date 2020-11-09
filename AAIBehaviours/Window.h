#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "MouseObserver.h"

class Window : public MouseObserver
{
public:

	Window(const int width, const int height);
	Window(const Window& w) = delete;
	~Window()
	{
		glfwTerminate();
		delete shader;
	}

	int Start();

private:
	GLFWwindow* window;

	Shader* shader;

	int width, height;

	GLFWwindow* SetupWindow(const int w, const int h);
};
