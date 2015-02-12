#pragma once

#include "TimeLine.h"
#include <iostream>
#include <string.h>
#include <map>


namespace Engine
{
	class TimeLineKey
	{
	private:
		float m_time;
		std::string m_event;
		// Time
		// Event string

	public:
		virtual ~TimeLineKey() {}
		virtual void Execute() = 0;
		virtual void Create(float triggerTime) = 0;

		virtual const char* GetTypeName() const = 0;
	};
}