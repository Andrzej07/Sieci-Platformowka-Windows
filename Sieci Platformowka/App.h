#pragma once

#include "MenuScreen.h"
#include "GameScreen.h"

class App
{
public:
	void run();

	App();
	~App();

private:
	void createWindow();

	MenuScreen m_menuscr;
	GameScreen m_gamescr;

	Window m_window;

	const int m_screenWidth;
	const int m_screenHeight;
};

