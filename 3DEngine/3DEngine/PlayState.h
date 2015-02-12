#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "Material.h"
#include "Player.h"

namespace Engine
{
	class PlayState : public GameState, public NonCopyable
	{
	public:
		PlayState();
		virtual void Draw();
		virtual void Update();
		virtual void OnActivated() override;
		virtual void OnDeActivated() override;
		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

	private:
		FontManager text;
		TextureManager texture;
		Material material;
		GLuint texId;
	};

	typedef Singleton<PlayState> ThePlayState;
}

#endif