#include "Timer.h"
#include <SDL\SDL.h>

Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::start()
{
	m_startTicks = SDL_GetTicks();
}
void Timer::stop()
{
	m_lastFrameTime = SDL_GetTicks() - m_startTicks;
}
unsigned int Timer::getFrameTime()
{
	return m_lastFrameTime;
}