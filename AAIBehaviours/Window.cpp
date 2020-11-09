#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

Window::Window(const int width, const int height)
	: width(width), height(height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

	window = glfwCreateWindow(width, height, "CG OpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	else
	{
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cout << "ERROR :: GLEW not ok" << std::endl;
		else
		{
			glEnable(GL_MULTISAMPLE);
		}
	}
}

int Window::Start()
{
	float delta = 0.0f;	// Time between current frame and last frame
	float time = 0.0f;
	float lastFrame = 0.0f; // Time of last frame

	while (!glfwWindowShouldClose(window))
	{
		time = (float)glfwGetTime();
		delta = time - lastFrame;
		lastFrame = time;

		// Clear current frame buffer
		glClearColor(0.2f, 0.05f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}