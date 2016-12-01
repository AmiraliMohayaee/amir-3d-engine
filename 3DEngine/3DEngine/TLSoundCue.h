#pragma once

#include "TimeLineKey.h"
#include "SoundManager.h"


namespace Engine
{
	class TLSoundCue : public TimeLineKey
	{
	public:
		virtual void Execute() override;
		virtual void Create(float triggerTime) override
		{
			
		}

		//virtual void Load() override;

	private:
		SoundManager m_soundEvent;
	};
}