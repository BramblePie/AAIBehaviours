#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Shader.h"
#include "MouseObserver.h"
#include "Sprite.h"

class Window : public MouseObserver
{
public:
	std::vector<Sprite*> sprites;

	Window(const int width, const int height);
	Window(const Window& w) = delete;
	~Window()
	{
		glfwTerminate();
		delete shader;
		for (auto s : sprites) delete s;
		sprites.clear();

		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
		glDeleteVertexArrays(1, &vao);
	}

	int Start();

private:
	GLFWwindow* window;

	Shader* shader;

	int width, height;

	GLFWwindow* SetupWindow(const int w, const int h);

	unsigned int vao, vbo, ibo;
	void initBuffers();
};
