#pragma once

#include "Camera2D.h"
#include "SpriteBatch.h"
#include "GLSLProgram.h"
#include "Window.h"
#include "Timer.h"
#include "Player.h"
// MOVE TO PLAYER CLASS
#include "InputManager.h"

class App
{
public:
	App();
	~App();
	void run();

private:

	void createWindow();
	void initSystems();
	void initShaders();
	void runLoop();
	void draw();
	void update(unsigned int frameTime);
	void processInput();

	Timer m_timer;
	Window m_window;
	InputManager m_inputManager;
	Camera2D m_camera;
	GLSLProgram m_shaderProgram;
	SpriteBatch m_spriteBatch;

	Player m_player1;

	const int m_screenWidth;
	const int m_screenHeight;
};

