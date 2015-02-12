#include "Image.h"
#include <assert.h>
#include <SDL_image.h>


//for conts, set any surface pointers to zero
Engine::Image::Image()
{
	m_surface = 0;
}

bool Engine::Image::Load(const std::string& filename)
{
	m_surface = IMG_Load (filename.c_str());


	return (m_surface != 0);
}

void Engine::Image::Draw(int x, int y)
{
	//making sure the Load function is called before the Draw function
	assert(m_surface);

	SDL_Rect desRect = { x, y, 0, 0 };

	SDL_BlitSurface(m_surface, 0, TheScreen::Instance()->GetSurface(), &desRect);
}