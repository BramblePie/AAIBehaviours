#include <iostream>

#include "Window.h"

#include "MouseObserver.h"

int main()
{
	Window* window = new Window(1200, 800);

	auto f = [](const int button, const int action, const int mod, const int x, const int y) {
		printf("Mouse click on ( %d, %d ) : button %d, isPressed %d, mods %d\n", x, y, button, action, mod);
	};

	auto& ob = *MouseObserver::GetObeserver();
	ob += f;

	window->Start();

	delete window;
	//system("pause");
}