#include "EventPoller.h"
#include <algorithm>

namespace Engine
{
	void EventPoller::AddHandler(EventHandler* eh)
	{
		m_handlers.push_back(eh);
	}

	void EventPoller::RemoveHandler(EventHandler* eh)
	{
		Handlers::iterator it = 
			std::find(m_handlers.begin(), m_handlers.end(), eh);

		if (it != m_handlers.end())
		{
			m_handlers.erase(it);
		}

		//Another way
		m_handlers.erase(
			std::remove(m_handlers.begin(),	m_handlers.end(), eh),
			m_handlers.end());
	}


	void EventPoller::Update()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e))
		{
			Handlers tempHandlers = m_handlers;
			for (unsigned int i = 0; i < tempHandlers.size(); i++)
			{
				tempHandlers[i]->HandleEvent(e);
			}
		}
	}
}