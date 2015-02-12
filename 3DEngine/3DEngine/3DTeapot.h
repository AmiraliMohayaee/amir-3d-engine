#pragma once

#include "MyGL.h"
#include <vector>
#include "Vec3.h"
#include "Frustum.h"
#include "Box3D.h"


namespace Engine
{
	class Teapot
	{
	public:
		Teapot(const Vec3f& pos) : m_pos(pos) 
		{
			m_box.Set(
				pos.x - 0.25f, pos.x + 0.25f, 
				pos.y - 0.25f, pos.y + 0.25f, 
				pos.z - 0.25f, pos.z + 0.25f);
		}

		bool Draw()
		{
			if (TheFrustum::Instance()->Intersects(m_box))
			{
				glPushMatrix();
					glTranslatef(m_pos.x, m_pos.y, m_pos.z);
					glutSolidTeapot(0.25f);
				glPopMatrix();
				m_box.Draw();
				return true;
			}
			return false;
		}

	private:
		Vec3f m_pos;
		Box3D m_box;
	};

	std::vector<Teapot> teapots;
}