#pragma once
class Timer
{
public:
	Timer();
	~Timer();

	void start();
	void stop();
	unsigned int getFrameTime();

private:
	unsigned int m_startTicks = 0;
	unsigned int m_lastFrameTime = 1;
};

