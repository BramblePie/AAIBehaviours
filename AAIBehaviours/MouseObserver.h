#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <set>
#include <functional>

#define PositionEvent std::function<void(const int, const int)>
#define MouseEvent std::function<void(const int button, const int action, const int mod, const int x, const int y)>

class MouseObserver
{
public:
	MouseObserver(const MouseObserver& mo) = delete;
	~MouseObserver()
	{
	}

	inline void operator+=(PositionEvent e) const
	{
		positionEvents.push_back(e);
	}

	inline void operator+=(MouseEvent e) const
	{
		mouseEvents.push_back(e);
	}

protected:
	MouseObserver(GLFWwindow* observing);

	// Target window given to observe
	GLFWwindow* observing;
private:

	mutable std::vector<PositionEvent> positionEvents;
	mutable std::vector<MouseEvent> mouseEvents;

	// Callback function on each cursor movement
	void pos_callback(GLFWwindow* target, const int xpos, const int ypos);

	// Callback function on mouse button events
	void button_callback(GLFWwindow* target, const int button, const int action, const int mod);

#pragma region Singleton access

private:
	static MouseObserver* singleton;

public:
	static const MouseObserver* GetObeserver()
	{
		return singleton;
	}

#pragma endregion
};