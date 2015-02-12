#ifndef EVENT_POLLER_H
#define EVENT_POLLER_H

#include "EventHandler.h"
#include "Singleton.h"
#include <vector>

namespace Engine
{
	class EventPoller
	{
	public:
		void Update();

		void AddHandler(EventHandler*);

		void RemoveHandler(EventHandler*);

	private:
		typedef std::vector<EventHandler*> Handlers;
		Handlers m_handlers;
	};

	typedef Singleton<EventPoller> TheEventPoller;
}

#endif