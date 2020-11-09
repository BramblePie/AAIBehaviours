#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

Window::Window(const int width, const int height)
	: MouseObserver(SetupWindow(width, height)), window(observing), width(width), height(height)
{
	shader = new Shader(width, height);
	shader->use();

	// set up vertex data (and buffer(s)) and configure vertex attributes
	float vertices[] = {
		100.0f, 100.0f, 0.0f,
		500.0f, 200.0f, 0.0f,
		200.0f, 500.0f, 0.0f,
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int Window::Start()
{
	if (window == NULL)
		return -1;

	float delta = 0.0f;	// Time between current frame and last frame
	float time = 0.0f;
	float lastFrame = 0.0f; // Time of last frame

	while (!glfwWindowShouldClose(window))
	{
		time = (float)glfwGetTime();
		delta = time - lastFrame;
		lastFrame = time;

		// Clear current frame buffer
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}

GLFWwindow* Window::SetupWindow(const int w, const int h)
{
	if (window != NULL)
	{
		std::cout << "GLFW window already present" << std::endl;
		return window;
	}

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

	GLFWwindow* attempt = glfwCreateWindow(w, h, "CG OpenGL", NULL, NULL);

	if (attempt == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}
	else
	{
		glfwMakeContextCurrent(attempt);

		if (glewInit() != GLEW_OK)
			std::cout << "ERROR :: GLEW not ok" << std::endl;
		else
			glEnable(GL_MULTISAMPLE);
	}
	return attempt;
}