#pragma once

#include "Vec3.h"
#include "Quaternion.h"
#include "RidgidBodyGO.h"
#include "Matrix.h"


namespace Engine
{
	class OBB3
	{
	public:
		OBB3() { }
		OBB3(const Vec3f& min, const Vec3f& max) : m_minVec(min), m_maxVec(max) {}
		
		void Draw() const;

		//OBB3 Set(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax) const;

		Vec3f Extend();
		Vec3f Centre(const OBB3& bb);

		bool Intersects(const OBB3& otherBox) const;

		bool Contains(const Vec3f& v) const;


	private:
		Vec3f m_minVec;
		Vec3f m_maxVec;

		Matrix m_mat[16];
	};
}