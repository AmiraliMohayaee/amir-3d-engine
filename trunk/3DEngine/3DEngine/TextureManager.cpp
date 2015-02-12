#include <SDL_image.h>
#include "MyGL.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include "Report.h"


namespace Engine
{
	TextureManager::TextureManager()
	{
		texId = -1;
		width = 0;
		height = 0;
		format = 0;
		data = 0;
	}

	bool TextureManager::Load(const std::string &filename)
	{
		glGenTextures(1, &texId);
		glBindTexture(GL_TEXTURE_2D, texId);

		SDL_Surface* surf = IMG_Load(filename.c_str());
		assert(surf);

		unsigned char* data = (unsigned char*) surf -> pixels;
		width = surf->w;
		height = surf->h;

		int bpp = surf->format->BytesPerPixel;

		if (bpp != 3 && bpp != 4)
		{
			SDL_FreeSurface(surf);

			ReportError("Wrong file type for " + filename);

			return false;
		}

		int format = GL_RGB;

		// Setting up alpha channel along with RGB
		if (bpp == 4)
		{
			format = GL_RGBA;
		}

		glTexImage2D(GL_TEXTURE_2D, 
			0, 
			format, 
			width, 
			height, 
			0, 
			format, 
			GL_UNSIGNED_BYTE,
			data);

		gluBuild2DMipmaps(
			GL_TEXTURE_2D,
			format,
			width,
			height,
			format,
			GL_UNSIGNED_BYTE,
			data);

		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER,
			GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR);

		SDL_FreeSurface(surf);

		return true;
	}

	void TextureManager::Draw()
	{
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texId);
	
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		//glDisable(GL_TEXTURE_2D);
	}

	// To enable Sphere mapping
	void TextureManager::EnableSphereMap()
	{
		glTexGeni(
			GL_S,
			GL_TEXTURE_GEN_MODE,
			GL_SPHERE_MAP);

		glTexGeni(
			GL_T,
			GL_TEXTURE_GEN_MODE,
			GL_SPHERE_MAP);
	}
}