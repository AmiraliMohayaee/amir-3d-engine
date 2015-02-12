#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "Singleton.h"
#include <SDL_mixer.h>
#include <iostream>

#undef PlaySound

namespace Engine
{
	class SoundManager
	{

	public:
		SoundManager();
		~SoundManager();
		bool PlaySound(
			const std::string& filename);

		bool PlayMusic(
			const std::string& filename);
	};

	typedef Singleton<SoundManager> TheSoundManager;
}

#endif