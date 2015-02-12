#pragma once

#include "Vec3.h"
#include "Vec2.h"
#include "Colour.h"

namespace Engine
{
	struct Vertex
	{
		Vertex()
		{
		}

		Vertex(const Vec3f& point) : m_point(point)
		{
		}


		void Draw()
		{
			m_colour.GetColours();
			m_colour.Draw();
			//glTexCoord2f(m_uv.x, m_uv.y);
			//glNormal3f(m_normal.x, m_normal.y, m_normal.z);
			glVertex3f(m_point.x, m_point.y, m_point.z);
		}

		void SetVertexColour(float red, float green, float blue, float alpha)
		{
			m_colour.SetColours(red, green, blue, alpha);
		}

		//float SetColours(float red, float green, float blue, float alpha)
		//{
		//	glColor4f(red, green, blue, alpha);
		//}


		Vec3f m_point;

		// TODO Add these other attributes if you like.
		Vec2f m_uv;
		Colour m_colour;
		Vec3f m_normal;
	};
}
