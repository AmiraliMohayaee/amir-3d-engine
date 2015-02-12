#include "EventHandler.h"
#include "EventPoller.h"

Engine::EventHandler::EventHandler()
{
	TheEventPoller::Instance()->AddHandler(this);

}

Engine::EventHandler::~EventHandler()
{
	TheEventPoller::Instance()->RemoveHandler(this);

}

void Engine::EventHandler::HandleEvent(const SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_QUIT:
		exit(0);
		break;

	case SDL_KEYUP:
		// Fall through
	case SDL_KEYDOWN:	
		OnKeyboardEvent(e.key);
		break;

	case SDL_MOUSEMOTION:
		OnMouseMotionEvent(e.motion);
		break;

	case SDL_MOUSEBUTTONUP:
		// Fall through
	case SDL_MOUSEBUTTONDOWN:
		OnMouseButtonEvent(e.button);
		break;
	}
}