#ifndef BILLBOARD_H
#define BILLBOARD_H

#include "Vec3.h"
#include "Vec2.h"

namespace Engine
{
	class Billboard
	{
	public:
		Billboard();
		void Draw(const Vec3f& pos, float s);


	private:
		Vec3f m_pos;
		Vec2f m_reg;
		float m_sqr;
	};
}

#endif