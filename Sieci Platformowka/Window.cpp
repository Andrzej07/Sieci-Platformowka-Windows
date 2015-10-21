#include "Window.h"
#include "Errors.h"


Window::Window()
{
}


Window::~Window()
{
}

int Window::create(const std::string &windowName, int screenWidth, int screenHeight, unsigned int passedFlags)
{
	Uint32 flags = SDL_WINDOW_OPENGL;

	if (passedFlags & INVISIBLE)
	{
		flags |= SDL_WINDOW_HIDDEN;
	}
	if (passedFlags & FULLSCREEN)
	{
		flags |= SDL_WINDOW_FULLSCREEN;
	}
	if (passedFlags & BORDERLESS)
	{
		flags |= SDL_WINDOW_BORDERLESS;
	}

	_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	if (_sdlWindow == nullptr)
	{
		fatalError("SDL Window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
	if (glContext == nullptr)
	{
		fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("glewInit failed!");
	}

	printf("****  OpenGL version: %s  ****\n", glGetString(GL_VERSION));

	glClearColor(1, 1, 1, 1);

	// Activate vsync
	SDL_GL_SetSwapInterval(1);

	// Enable alpha blend
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SDL_GL_SetSwapInterval(1);
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	return 0;
}

void Window::swapBuffer()
{
	SDL_GL_SwapWindow(_sdlWindow);
}
