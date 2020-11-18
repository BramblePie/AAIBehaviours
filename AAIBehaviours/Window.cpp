#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Agent.h"

Window::Window(const int width, const int height)
	: MouseObservable(SetupWindow(width, height)), width(width), height(height)
{
	shader = new Shader(width, height);
	shader->use();

	auto agent = new Agent();
	subscribe(agent);
	sprites.push_back(agent);

	initBuffers();
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
		unsigned int i_off = 0u;
		unsigned int size;
		for (auto s : sprites)
		{
			shader->SetTransform(s->GetTransform());
			size = (unsigned int)s->GetIndices().size();
			glDrawRangeElements(GL_TRIANGLES, i_off, i_off + size - 1, size, GL_UNSIGNED_INT, 0);
			i_off += size;
		}

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

	window = attempt;
	return attempt;
}

void Window::initBuffers()
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	for (auto sprite : sprites)
	{
		vertices.insert(vertices.end(), sprite->GetVertices());
		indices.insert(indices.end(), sprite->GetIndices());
	}

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	// Hard coded vector 2 float attribute
	glEnableVertexAttribArray(Shader::pos_attrib_location);
	glVertexAttribPointer(Shader::pos_attrib_location, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
}
