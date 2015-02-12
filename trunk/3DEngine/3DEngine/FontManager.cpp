#include "FontManager.h"
#include "MyGL.h"
#include "Vec2.h"


namespace Engine
{
	FontManager::FontManager()
	{
		//m_size = 0;
		m_numCellsX = 0;
		m_numCellsY = 0;
	}

	bool FontManager::Load(const std::string& fontFilename,
		float numCellsX,
		float numCellsY)
	{
		if (!m_tex.Load(fontFilename))
		{
			return false;
		}

		m_numCellsX = numCellsX;
		m_numCellsY = numCellsY;

		return true;
	}

	void FontManager::Draw(const std::string& text,
		float x, float y, float size)
	{
		m_tex.Draw();

		float w = 1.0f / (float)m_numCellsX;
		float h = 1.0f / (float)m_numCellsY;

		float pos = 0;

		// Putting GL begin and GLend outside of 
		// the loop 
		glBegin(GL_QUADS);
		// Loop for iterating through the fonts
		for (unsigned int i = 0; 
			i < text.size(); ++i)
		{
			char c = text[i];


			// Working out coords and UV here
			Vec2f topLeftUV(c % m_numCellsX * w, c / m_numCellsX * h);
			Vec2f topLeftCoord(x + pos, y);

			Vec2f bottomLeftUV = topLeftUV + Vec2f(0, h);
			Vec2f bottomLeftCoord(x + pos, y - size);

			Vec2f bottomRightUV = topLeftUV + Vec2f(w, h);
			Vec2f bottomRightCoord(x + pos + size, y - size);

			Vec2f topRightUV = topLeftUV + Vec2f(w, 0);
			Vec2f topRightCoord(x + pos + size, y);


			glTexCoord2f(topLeftUV.x, topLeftUV.y);
			glVertex2f(topLeftCoord.x, topLeftCoord.y);

			glTexCoord2f(bottomLeftUV.x, bottomLeftUV.y);
			glVertex2f(bottomLeftCoord.x, bottomLeftCoord.y);

			glTexCoord2f(bottomRightUV.x, bottomRightUV.y);
			glVertex2f(bottomRightCoord.x, bottomRightCoord.y);

			glTexCoord2f(topRightUV.x, topRightUV.y);
			glVertex2f(topRightCoord.x, topRightCoord.y);

			pos += size;
		}
		glEnd();
	}

	void FontManager::printText(float x, float y, const std::string& text)
	{
		glRasterPos2f(x, y);
		for (unsigned int k=0; k < text.size(); k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12/*GLUT_BITMAP_TIMES_ROMAN_24*/, text[k]);
		}
	}
}