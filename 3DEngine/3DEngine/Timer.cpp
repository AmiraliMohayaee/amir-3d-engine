#include "Timer.h"
//#include "Animation.h"
#include <SDL.h>
#include <cstdlib>

void DestroyTimer()
{
	delete Engine::Timer::Instance();
}

namespace Engine
{
	Timer* Timer::Instance()
	{
		// One way of doing it
		static Timer myTimer;
		return &myTimer;

		// Another Way
		//static Timer* myTimerP = 0;
		//if (!myTimerP)
		//{
		//	myTimerP = new Timer;
		//	atexit(DestroyTimer());
		//}
		//return myTimerP;
	}

	Timer::Timer()
	{
		m_dt = 0;
	}


	float Timer::GetDt() const
	{
		return m_dt;
	}

	void Timer::Update()
	{
		static unsigned int oldticks = SDL_GetTicks();
		unsigned int newticks = SDL_GetTicks();

		unsigned int diff = newticks - oldticks;

		oldticks = newticks;

		m_dt = static_cast<float>(diff) * 0.001f;
		//This could also be undertaken if dt was an int variable 
		//m_dt = static_cast<float>(diff) / 1000.0f;

		const float MAX_DT = 0.1f;
		if (m_dt > MAX_DT)
		{
			m_dt = MAX_DT;
		}

		//m_pos = m_velocity * dt;
	}
}