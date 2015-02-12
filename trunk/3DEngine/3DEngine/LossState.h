#ifndef LOSS_STATE_H
#define LOSS_STATE_H

#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "Car.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "Material.h"

namespace Engine
{
	class LossState : public GameState, public NonCopyable
	{
	public:
		LossState();
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

	typedef Singleton<LossState> TheLossState;
}

#endif