#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include "MyGL.h"
#include "TextureManager.h"

namespace Engine
{
	class FontManager
	{
	public:
		FontManager();

		void Draw(const std::string& text, float x, float y, float size);

		bool Load(const std::string& fontFilename,
			float numCellsX,
			float numCellsY);

		// Function using Glut font capabilities
		// This has a rather limited number of fonts however and
		// not very flexible
		void printText(float x, float y, const std::string& text);


	private:
		int m_numCellsX;
		int m_numCellsY;
		//float m_size;
		TextureManager m_tex;
	};
}

#endif