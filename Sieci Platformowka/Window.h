#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <string>


enum WindowFlags { INVISIBLE = 1, FULLSCREEN = 2, BORDERLESS = 4 };

class Window
{
public:
	Window();
	~Window();

	int create(const std::string &windowName, int screenWidth, int screenHeight, unsigned int flags);

	void swapBuffer();

	int getScreenHeight() { return _screenHeight; }
	int getScreenWidth() { return _screenWidth; }

private:
	SDL_Window* _sdlWindow;
	int _screenWidth;
	int _screenHeight;
};
