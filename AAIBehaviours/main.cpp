#include <iostream>

#include "Window.h"
#include "Behaviours.h"

#include <glm/glm.hpp>

int main()
{
	Window* window = new Window(1200, 800);

	Agent* seeker = new Agent(new SeekBehaviour());
	Agent* arrive = new Agent(new ArriveBehaviour());

	window->AddEntity((IEntity*)seeker);
	window->AddEntity((IEntity*)arrive);

	window->Subscribe(seeker);
	window->Subscribe(arrive);

	window->Start();
	//system("pause");

	delete window;
}
