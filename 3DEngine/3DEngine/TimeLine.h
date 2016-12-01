////////////////////////////////////////////////////////////////
////	TimeLine
////	Author: Amirali Mohayaee
////	For fancy triggers in states. 
////	Acts as a base class.
////	Last update: 21/05/2015
////////////////////////////////////////////////////////////////


#pragma once

#include <iostream>
#include <queue>
#include <map>
#include "Singleton.h"
#include "Factory.h"
#include "SmartPointer.h"
#include "TimeLineKey.h"


namespace Engine
{
	class TimeLine
	{
	public:
		TimeLine();
		TimeLine(bool loop) : m_loop(loop) { }
		//~TimeLine();

		void AddTimeLineKey(TimeLineKey* tlk);

		bool Load(const std::string &filename);
		bool Initialize();

		void PrintTime();
		void Update();

	private:
		float m_currentTime;
		bool m_loop;


		//std::map<int key, int time, m_timekey> m_tKey;
		std::queue<TimeLineKey*> m_timekey;	// Change to contrainer of smrtPtrs?
	};

	typedef Singleton< Factory<TimeLineKey> > TheTLKFactory;
}