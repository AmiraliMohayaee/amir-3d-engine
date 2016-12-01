#pragma once

#include "TimeLine.h"
#include <iostream>
#include <string.h>
#include <map>


namespace Engine
{
	class TimeLineKey
	{
	public:
		virtual ~TimeLineKey() {}
		virtual void Execute() = 0;
		virtual void Create(float triggerTime) = 0;

		void SetExecTime(float executeTime) { m_executeTime = executeTime; }
		
		float GetExecTime() 
		{
			return m_executeTime;
		}
		
	
	private:
		// The time passed after the previous TLK in the factory was executed
		float m_executeTime;
		std::string m_name;
	};
}