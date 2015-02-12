#pragma once

#include "Vec3.h"
#include "LineSeg3.h"
#include <algorithm>


namespace Engine
{
	class PlaneEquation
	{
	private:
		Vec3f m_normal; 
		float m_d; 

		void Normalize(); 
	public:

		PlaneEquation(); 

		PlaneEquation(const Vec3f& a, const Vec3f& b, const Vec3f& c); 

		void CreatePlaneAndCrossProductIt(const Vec3f& a, const Vec3f& b, const Vec3f& c); 

		float DistanceFromPoint(const Vec3f& p); 

		float DistanceToLineSeg(const LineSeg3& a); 

	protected:

	};
}