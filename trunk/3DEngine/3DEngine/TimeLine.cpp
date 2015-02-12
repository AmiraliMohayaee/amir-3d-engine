//#include "TimeLine.h"
//#include "File.h"
//#include "Timer.h"
//
//
//namespace Engine
//{
//	TimeLine::TimeLine()
//	{
//		//m_timePassed = 0;
//	}
//
//	bool TimeLine::Load(const std::string &filename)
//	{
//		File f;
//
//		if(!f.OpenRead(filename))
//		{
//			return false;
//		}
//
//		std::string line;
//		while(f.GetLine(&line))
//		{
//			float abstime = atof(line.c_str());
//
//			std::string s;
//			if(!f.GetLine(&s))
//			{
//				("Expected a Time Line Key.");
//
//				return false;
//			}
//
//			TimeLineKey* tlk = TheTLKFactory::Instance()->Create(s);
//
//			m_timekeys.insert(std::make_pair(abstime, tlk));
//
//			return true;
//		}
//	}
//
//	void TimeLine::Update(float dt)
//	{
//		//m_keys[m_currentKey]->Execute();
//
//		// Check container size
//		// If true, get the timelinekeys from the timeline container
//		// check if the timepassed local timer is >= the timelinekey time
//		// print the time of the tlk
//		// Execute it
//		// reset the time passed since last tlk executed
//
//		if (m_timekeys >= 0)
//		{
//
//		}
//
//
//		// Increment time after loop
//		m_timePassed += Timer::Instance()->GetDt();
//	}
//}