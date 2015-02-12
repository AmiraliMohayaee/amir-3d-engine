#pragma once

#include "libsndfile/include/sndfile.h"
#include <stdio.h>
#include <string>
#include <vector>
#include "include/portaudio.h"
#include "Vec3.h"
#include <math.h>
#include "File.h" 
#include "Singleton.h"
#include "Non-Copyable.h"


namespace Engine
{
	class PortSndAudioManager : public NonCopyable
	{
	public:
		friend Singleton<PortSndAudioManager>;

		~PortSndAudioManager();
	
		void PAInitialize();
		void PATerminate();

		// For a mixing func add up two signals and devide by two


	private:
		//SNDFILE* m_soundFile;
		//SF_INFO m_sfInfo; 
		PortSndAudioManager();

		int m_pos;
		Vec3f m_soundPos;	//Vec positioning to replace int positioning later
		Vec3f m_reverbPos;

		PaError m_error;
	};

	typedef Singleton<PortSndAudioManager> TheAudioManager;
}