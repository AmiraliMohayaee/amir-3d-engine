#pragma once

#include <map>
#include <iostream>
#include "Singleton.h"
#include "Non-Copyable.h"
#include "Factory.h"
#include "EventHandler.h"
#include "TimeLineKey.h"
#include "Timer.h"


namespace Engine
{
	class TimeLineKey;

	class TimeLine
	{
	private:
		float m_currentTime;
		//TimeLineKey m_timekey;

	public:
		//TimeLine() {} 
		//bool Load(const std::string &filename);
		//void Update(float dt);


		void PrintTime()
		{
			// print out system of get sdl ticks
			float deltaTime = Timer::Instance()->GetDt();
			//float currentTime = 0;
			float intervalTime = 0;

			for (int i = 0; i <= 30; i++)
			{
				deltaTime++;
				intervalTime++;

				std::cout << "Current time is " << deltaTime
					<< " .\n";

				std::cout << "The interval time is at " << intervalTime 
					<< " .\n";

				// Resets the interval timer every 5 seconds
				if (intervalTime >= 5)
				{ 
					std::cout << "Interval timer has reset.\n";
					intervalTime = 0;
				}

				if (deltaTime > 30.0f)
				{
					std::cout << "Timer limit reached. Stopping...\n";
					break;
				}
			}
		}

		void Update()
		{
			PrintTime();
		}
	};

	//typedef Singleton<Factory<TimeLineKey> > TheTLKFactory;
}