#include "Screen.h"
#include <assert.h>
#include <SDL_video.h>
#include "MyGL.h"


namespace Engine
{
	Screen::Screen()
	{
		m_surface = 0;
	}

	bool Screen::Init(unsigned int width, 
		unsigned int height, bool fullscreen)
	{
		unsigned int flags = SDL_SWSURFACE | SDL_OPENGL;
		if (fullscreen)
		{
			flags |= SDL_FULLSCREEN;
		}

		m_surface = SDL_SetVideoMode(width, height, 0, flags); //(Width, Height, Depth, Flags);

		return (m_surface != 0);
	}

	void Screen::Flip()
	{
		assert(m_surface != 0);

		SDL_GL_SwapBuffers(); // specific for SDL-GL buffering
	}

	// Clear screen is not really needed at this point 
	// as we are already flipping buffers which draws 
	// a new frame over the older one.
	//void Engine::Screen::Clear()
	//{
	//	assert(m_surface != 0);
	//
	//	glClearColor(0, 0, 0, 0);
	//
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//}

	SDL_Surface* Screen::GetSurface()
	{
		return m_surface;
	}
}