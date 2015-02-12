#include "GameState.h"
#include "EventPoller.h"


namespace Engine
{
	void GameState::OnActivated()
	{
		m_elapsedTime = 0;

		TheEventPoller::Instance()->AddHandler(this);
	}

	void GameState::OnDeActivated()
	{
		TheEventPoller::Instance()->RemoveHandler(this);
	}
}