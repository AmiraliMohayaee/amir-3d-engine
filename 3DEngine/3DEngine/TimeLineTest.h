#pragma once

#include "TimeLineKey.h"
#include "SoundManager.h"

namespace Engine
{
	class TimeLineTest : public TimeLineKey
	{
	private:


	public:
		virtual void Execute() override
		{
			SoundManager sm;
			sm.PlaySound("assets/sounds/DoomSounds/plasma_impact1.wav");
		}

		virtual void Create(float triggerTime) override
		{

		}

	};
}