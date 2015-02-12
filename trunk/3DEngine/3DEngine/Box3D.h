#pragma once

#include "Vec3.h"


namespace Engine
{
	class Box3D
	{
	public:
		Box3D() {}
		Box3D(const Vec3f& min, const Vec3f& max) : m_minVec(min), m_maxVec(max) { }

		void Draw() const;

		//void SetIf(float x, float y, float z);	// I forgot what this was supposed to do

		//void Set(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);

		bool Intersects(const Box3D& otherBox) const;

		Box3D MakeOctreeChild(int octant) const;

		bool Contains(const Vec3f& v) const;


	public:
		Vec3f m_minVec;
		Vec3f m_maxVec;
	};
}