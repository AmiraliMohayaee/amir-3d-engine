#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "EventHandler.h"

namespace Engine
{
	//GameState acts as an abstract base class
	class GameState : public EventHandler
	{
	public:
		virtual ~GameState() = 0 {}

		virtual void Draw() = 0;
		virtual void Update() = 0;

		virtual void OnActivated();
		virtual void OnDeActivated();

	protected:
		float m_elapsedTime;
	};
}

#endif