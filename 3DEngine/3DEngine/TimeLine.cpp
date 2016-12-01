#include "TimeLine.h"
#include "Timer.h"
#include "File.h"


namespace Engine
{
	TimeLine::TimeLine() : m_currentTime(0.0f)
	{

	}


	void TimeLine::PrintTime()
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


	void TimeLine::AddTimeLineKey(TimeLineKey* tlk)
	{
		m_timekey.push(tlk);
	}


	bool TimeLine::Load(const std::string &filename)
	{
		File f;

		// Checking file reading
		if(!f.OpenRead(filename))
		{
			("Expected a Time Line Key.");
			return false;
		}

		// Loop reading the TLK file line by line
		std::string line;


		// Reading the next line
		while(f.GetLine(&line))
		{
			// split the line
			Strings strs = Split(line, ' ');
			
			// The time the TLK should execute
			if (strs[0] == "tlk")
			{
				float abstime = atof(line.c_str());
				
				// Creating 
				TimeLineKey* tlk = TheTLKFactory::Instance()->Create(line);
			
				// Adding the new TLK to the queue
				AddTimeLineKey(tlk);
			
				//m_timekey.push(std::make_pair(abstime, tlk));

				continue;
			}
			
			if (strs[0] == "exec time")
			{
				TimeLineKey* tlk = TheTLKFactory::Instance()->Create(line);

				m_timekey.push(tlk);
				

			}

			return true;
		}

		return true;	// Still incomplete, so I'm not sure
	}

	void TimeLine::Update()
	{
		//// Check container size
		//// If true, get the timelinekeys from the timeline container
		//// check if the timepassed local timer is >= the timelinekey time
		//// print the time of the tlk
		//// Execute it
		//// reset the time passed since last tlk executed

		if (m_timekey.size() <= 0)
			return;
	
		m_currentTime += Timer::Instance()->GetDt();
	
		if (m_currentTime >= m_timekey.front()->GetExecTime() )
		{
			//do the thing
			m_timekey.front()->Execute();

			//reset the timer, not removing any overshoot
			m_currentTime -= m_timekey.front()->GetExecTime();
			if (m_loop)
			{
				//put top one on to the back
				m_timekey.push(m_timekey.front());
			}

			m_timekey.pop();
		}
	}
}







			//std::string s;
			//if(!f.GetLine(&s))
			//{
			//	return false;
			//}