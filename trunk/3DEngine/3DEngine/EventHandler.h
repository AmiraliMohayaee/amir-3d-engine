#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL.h>
//#include <AntTweakBar.h>


namespace Engine
{
	class EventHandler
	{
	public:
		EventHandler();

		virtual ~EventHandler();

		void HandleEvent(const SDL_Event&);

		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&) {}

		virtual void OnMouseMotionEvent(const SDL_MouseMotionEvent&) {}

		virtual void OnMouseButtonEvent(const SDL_MouseButtonEvent&) {}

		virtual void OnJoyStickAxisEvent(const SDL_JoyAxisEvent&) {}
	};
}

#endif