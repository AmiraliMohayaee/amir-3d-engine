#ifndef IMAGE_H
#define IMAGE_H

#include <SDL_image.h>
#include <string>
#include "Screen.h"

// Used for loading images in the 2D environment

namespace Engine
{
	class Image
	{
	public:
		Image();
		bool Load(const std::string& filename); //using IMG_Load()
		void Draw(int x, int y);

	protected:
		SDL_Surface* m_surface;
	};
}

#endif