#pragma once


#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "Car.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "SoundFile.h"

namespace Engine
{
	class AudioDemoState : public GameState, public NonCopyable
	{
	public:
		AudioDemoState();
		virtual void Draw();
		virtual void Update();
		virtual void OnActivated() override;
		virtual void OnDeActivated() override;

		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);
	private:
		TextureManager texture;
		SoundFile m_soundFile;
		FontManager text;
		GLuint texId;
	};

	typedef Singleton<AudioDemoState> TheAudioDemoState;
}