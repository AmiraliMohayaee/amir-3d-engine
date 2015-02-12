#ifndef TRI_H
#define TRI_H

#include <vector>
#include "Vec3.h"
#include "Vertex.h"
#include "Mgc/MgcDistLin3Tri3.h"

namespace Engine
{
	struct Tri
	{
		Tri() {}

		Vertex verts[3];

		Vec3f Centre() const
		{
			return Vec3f((verts[0].m_point + verts[1].m_point + verts[2].m_point) * (1.0f/3.0f));
		}

		void Draw()
		{
			glBegin(GL_TRIANGLES);
			for (int i = 0; i < 3; i++)
			{
				verts[i].Draw();
			}
			glEnd();
		}

		void SetTriColour(float r, float g, float b, float a)
		{
			for (int i = 0; i < 3; i++)
			{
				verts[i].SetVertexColour(r, g, b, a);
			}
		}
	};

	typedef std::vector<Tri> Tris;

}

#endif