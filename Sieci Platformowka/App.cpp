#include "App.h"


App::App() :
m_screenWidth(1440),
m_screenHeight(900)
{
}


App::~App()
{
}

void App::run()
{
	createWindow();
	while (true)
	{
		MenuReturn userChoice = m_menuscr.run(&m_window);
		switch (userChoice)
		{
		case MenuReturn::SINGLEPLAYER:
			m_gamescr.run(&m_window);
			break;
		case MenuReturn::MULTIPLAYER:
			break;
		case MenuReturn::EDITOR:
			break;
		case MenuReturn::NONE:
			break;
		}
	}
}

void App::createWindow()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	m_window.create("Super Platformer", m_screenWidth, m_screenHeight, 0);
}