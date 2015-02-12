#include "SoundFile.h"


namespace Engine
{
	SoundFile::~SoundFile()
	{
		StopStream();

		if (m_stream)
			Pa_CloseStream(m_stream);
	}

	// The Callback function takes care of taking in the file and allocating the
	// momeory block for the audio file
	static int PACallback(const void *inputBuffer, void *outputBuffer, unsigned long frameBufferCount,
		const PaStreamCallbackTimeInfo* paTimeInfo, PaStreamCallbackFlags statusFlags,
		void *userData)
	{
		float *inbuff = (float *)inputBuffer;
		float *outbuff = (float *)outputBuffer;

		static double phase = 0;
		//unsigned long i;

		// Casting the userdata into a sound data
		SoundFile* sound = static_cast<SoundFile*>(userData);
	
		// Checking size of output buffer
		unsigned int size = sound->GetNumChannels() * frameBufferCount;

		for (unsigned int i = 0; i < size; i++)
		{
			//float sine = sin(phase);
			//*outbuff = *inbuff++  * sine; // Left Channel
			//*outbuff = *inbuff++  * sine; // Right Channel
			//phase += si;
			outbuff[i] = sound->GetCurrentFrame();
		}

		return paContinue;
	}


	float SoundFile::GetCurrentFrame()
	{
		// Check if we're not at the last frame and attempt to loop
		if (m_currentFrame > ((m_numFrames * m_numchannels) - 1))
		{
			Pa_CloseStream(m_stream);

			m_play = false;

			m_currentFrame = 0;

			return 0.0f;
		}


		m_currentFrame++;

		return m_data[m_currentFrame-1];
	}

	unsigned int SoundFile::GetNumChannels()
	{
		return m_numchannels;
	}


	// Loading in raw sound data
	bool SoundFile::Load(const std::string& filename)
	{
		SNDFILE *audioFile;
		SF_INFO sfInfo;
	
		// Getting sound file details and making it readable
		audioFile = sf_open(filename.c_str(), SFM_READ, &sfInfo);

		if (!audioFile)
			return false;
		
		// Resizing the vector for it to fit the sound data
		m_data.assign(static_cast<unsigned int>(sfInfo.frames * sfInfo.channels), 0);

		// Checking if all elements from the sound data are copied properly
		sf_count_t frameCount = sf_readf_float(audioFile, &m_data[0], static_cast<unsigned int>(sfInfo.frames));
		
		if (frameCount != sfInfo.frames)
		{
			std::cout << "Not all elements from file were copied properly. Data lost.";
			return false;
		}

		// Creating a stream
		PaError err = Pa_OpenDefaultStream(&m_stream, 0 , sfInfo.channels, paFloat32, sfInfo.samplerate, 
			paFramesPerBufferUnspecified, PACallback, this);

		if (err != paNoError)
			return false;

		m_numchannels = static_cast<unsigned int>(sfInfo.channels);
		m_numFrames = static_cast<unsigned int>(sfInfo.frames);
		m_samplerate = static_cast<unsigned int>(sfInfo.samplerate);

		// We're done with checking the audiofile
		sf_close(audioFile);


		return true;
	}


	bool SoundFile::StartStream()
	{
		if (!m_stream)
			return false;

		m_currentFrame = 0;

		PaError err;
		err = Pa_StartStream( m_stream );
		if( err != paNoError ) 
		{
			printf ("Playing Stream...\n");
			return false;
		}

		m_play = true;

		return true;
	}


	bool SoundFile::StopStream()
	{
		if (!m_stream)
			return false;

		PaError err;
		err = Pa_StopStream( m_stream );
		if( err != paNoError ) 
		{
			printf("Stopping Stream...\n");
			return false;
		}

		m_play = false;

		m_currentFrame = 0;

		return true;
	}
}


// playing sound using callback

	// /* Cast data passed through stream to our structure. */
	//TheSoundPool *data = (TheSoundPool *)userData;
	//float *out = (float*)outputBuffer;
	//unsigned int i;
	//(void) inputBuffer; /* Prevent unused variable warning. */

	//for( i=0; i<frameBufferCount; i++ )
	//{
	//	*out++ = data->m_leftPhase; /* left */
	//	*out++ = data->m_rightPhase; /* right */
	//	/* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
	//	data->m_leftPhase += 0.01f;
	//	/* When signal reaches top, drop back down. */
	//	if( data->m_leftPhase >= 1.0f ) data->m_leftPhase -= 2.0f;
	//	/* higher pitch so we can distinguish left and right. */
	//	data->m_rightPhase += 0.03f;
	//	if( data->m_rightPhase >= 1.0f ) data->m_rightPhase -= 2.0f;
	//}



// Old callback func


	//float *cursor;
	//float thisSize = frameBufferCount;
	//int thisRead;

	//outbuf = cursor;

	////int r;
	//for (int i = 0; i < thisSize; i++)
	//{
	//	float frame = 
	//	*outbuf++ = r;
	//}

	//while (thisSize > 0)
	//{
	//	sf_seek(&data->audioFile, data->position, SEEK_SET);

	//	if (thisSize > (data->sfInfo.frames - data->position))
	//	{
	//		thisRead = data->sfInfo.frames - data->position;
	//		data->position = 0;
	//	}
	//	else
	//	{
	//		thisRead = thisSize;
	//		data->position += thisRead;
	//	}

	//	sf_readf_int(data->audioFile, cursor, thisRead);
	//	cursor += thisRead;
	//	thisSize -= thisRead;
	//}