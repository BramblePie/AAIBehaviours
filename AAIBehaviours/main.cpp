#include <iostream>

#include "Window.h"

#include <glm/glm.hpp>

int main()
{
	Window* window = new Window(1200, 800);

	window->Start();
	//system("pause");

	delete window;
}
