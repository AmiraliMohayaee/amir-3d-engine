#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include "Singleton.h"

namespace Engine
{
	class Screen : public NonCopyable
	{
	private:
		Screen();
		friend class Singleton<Screen>;

	public:
		bool Init(
			unsigned int width, 
			unsigned int height, 
			bool fullscreen);
		void Flip();
		//void Clear();

		SDL_Surface* GetSurface();

	private:
		SDL_Surface* m_surface;
	};

	typedef Singleton<Screen> TheScreen;
}

#endif