#ifndef AI_DEMO_STATE_H_INCLUDED
#define AI_DEMO_STATE_H_INCLUDED

#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "Material.h"
#include "Graph.h"

namespace Engine
{
	class AIDemoState : public GameState, public NonCopyable
	{
	public:
		AIDemoState();
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
		Graph bfgraph;
		Graph dfgraph;
		Graph dgraph;
		Graph aSgraph;
	};

	typedef Singleton<AIDemoState> TheAIDemoState;
}

#endif