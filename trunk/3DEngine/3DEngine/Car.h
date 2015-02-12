#ifndef CAR_H
#define CAR_H

#include "MyGL.h"
#include "EventPoller.h"
#include "EventHandler.h"
#include "GameObject.h"

namespace Engine
{
	class Car : public EventHandler
	{
	public:
		Car();
		void Draw();
		void Update();

		void HandleEvent(const SDL_Event&);

	private:
		float m_vel;
		float m_acc;
		float m_pos;
		float m_turn;
		float m_wheelTurn;

	};
}

#endif