#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Shader.h"
#include "MouseObservable.h"
#include "Agent.h"

class Window : public MouseObservable
{
public:

	Window(const int width, const int height);
	Window(const Window& w) = delete;
	~Window()
	{
		glfwTerminate();
		delete shader;
		for (auto s : sprites) delete s;
		sprites.clear();
		agents.clear();

		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
		glDeleteVertexArrays(1, &vao);
	}

	int Start();

	void AddAgent(Agent* agent);

private:
	GLFWwindow* window;

	Shader* shader;

	int width, height;

	std::vector<Sprite*> sprites;
	std::vector<Agent*> agents;

	GLFWwindow* SetupWindow(const int w, const int h);

	unsigned int vao, vbo, ibo;
	void initBuffers();
};
