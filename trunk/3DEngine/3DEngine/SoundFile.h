#pragma once

#include "libsndfile/include/sndfile.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "include/portaudio.h"



namespace Engine
{
	class SoundFile
	{
	private:	
		float m_leftPhase, m_rightPhase;
		//unsigned int streamPosition;
		double long si;

		unsigned int m_numchannels;
		unsigned int m_samplerate;
		// Current position in the stream
		unsigned int m_currentFrame;
		unsigned int m_numFrames;
		float m_volume;
		bool m_play;

		typedef std::vector<float> Data;
		Data m_data;
		PaStream* m_stream;
	

	public:
		SoundFile() :
		m_numchannels(0),
		m_samplerate(0),
		m_currentFrame(0),
		m_numFrames(0),
		m_volume(0),
		m_play(0) {}

		~SoundFile();


		bool Load(const std::string& filename);
		float GetCurrentFrame();
		unsigned int GetNumChannels();

		bool StartStream();
		bool StopStream();
	};
}