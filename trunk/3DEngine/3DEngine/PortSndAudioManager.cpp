#include "SoundManager.h"
#include "include/portaudio.h"
#include <iostream>
#include <math.h>
#include "File.h"
#include "PortSndAudioManager.h"


namespace Engine
{
	PortSndAudioManager::PortSndAudioManager()
	{
		PAInitialize();
	}


	PortSndAudioManager::~PortSndAudioManager()
	{
		PATerminate();
	}


	void PortSndAudioManager::PAInitialize()
	{
		// Initializing Port Audio while checking errors
		m_error = Pa_Initialize();
		if (m_error != paNoError)
			exit(0);

		//char* paVersion = Pa_GetVersionText();
		//printf("Current Port Audio version is 0x%x", &paVersion);

		int numDevices = Pa_GetDeviceCount();
		if (numDevices < 0)
		{
			printf("Error: Pa returned 0x%x for device count", numDevices);
			m_error = numDevices;
		}
	}

	void PortSndAudioManager::PATerminate()
	{
		PaError err = Pa_Terminate();

		if( err != paNoError )
		printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );
	}
}







	//void Amplitude(float range)
	//{
	//	float random = 0;

	//	for (int r = 0; r < range; r++)
	//	{
	//		r = rand(static_cast<int*>(random));

	//		if (r < 

	//		return random;
	//	}
	//	
	//	float amp = amp/44100.0;
	//	x = (
	//}