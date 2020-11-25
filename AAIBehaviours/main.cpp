#include <iostream>

#include "Window.h"
#include "Behaviours.h"

#include <glm/glm.hpp>

int main()
{
	Window* window = new Window(1200, 800);

	window->AddAgent(new Agent(new SeekBehaviour()));
	window->AddAgent(new Agent(new ArriveBehaviour()));

	window->Start();
	//system("pause");

	delete window;
}