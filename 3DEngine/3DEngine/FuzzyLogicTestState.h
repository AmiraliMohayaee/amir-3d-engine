#ifndef FUZZY_LOGIC_TEST_STATE_H_INCLUDED
#define FUZZY_LOGIC_TEST_STATE_H_INCLUDED

#include "ffllapi/FFLLAPI.h"

#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "FontManager.h"
//#include "FFLLAPI.h"

namespace Engine
{
	class FuzzyLogicTestState : public GameState, public NonCopyable
	{
	public:
		FuzzyLogicTestState();
		virtual void Draw();
		virtual void Update();
		virtual void OnActivated() override;
		virtual void OnDeActivated() override;

		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);
	private:
		FontManager text;
		GLuint texId;

		float	our_health;
		float	enemy_health;
		char option;

	};

	typedef Singleton<FuzzyLogicTestState> TheFuzzyLogicTestState;
}

#endif