#include "SoundManager.h"
#include <assert.h>


Engine::SoundManager::SoundManager()
{
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;

	if (Mix_OpenAudio(audio_rate, audio_format,
		audio_channels, audio_buffers) != 0)
	{

	}
}

Engine::SoundManager::~SoundManager()
{

}

bool Engine::SoundManager::PlaySound(const std::string& filename)
{
	Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
	assert(sound);
	int channel = Mix_PlayChannel(-1, sound, 0);

	return true;
}

bool Engine::SoundManager::PlayMusic(const std::string& filename)
{
	Mix_Music* music = 0;

	music = Mix_LoadMUS(filename.c_str());
	assert(music);
	Mix_PlayMusic(music, -1);

	return true;

	/*for(music = 0; music < 5; music++)
	{
	}
	*/
}