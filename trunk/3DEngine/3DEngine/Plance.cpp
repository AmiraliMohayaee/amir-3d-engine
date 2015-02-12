#include "Plane.h"

namespace Engine
{
	PlaneEquation::PlaneEquation()
	{
		m_d = 0.0f; 
	}

	PlaneEquation::PlaneEquation(const Vec3f& a, const Vec3f& b, const Vec3f& c)
	{
		m_normal = CrossProduct((c - a), (b - a)); 

		m_d = DotProduct(a, m_normal); 

		Normalize(); 
	}

	void PlaneEquation::Normalize()
	{
		float n = 1 / m_normal.Length(); 

		m_normal *= n; 
		m_d *= n; 
	}

	void PlaneEquation::CreatePlaneAndCrossProductIt(const Vec3f& a, const Vec3f& b, const Vec3f& c)
	{
		m_normal = CrossProduct((c - a), (b - a));

		m_d = DotProduct(a, m_normal);

		Normalize();
	}

	//if the result < 0 then the point is behind the plane 
	// if the result > 0 then the pint is in front of the plane 
	// front is defined by which direction is the normal facing

	float PlaneEquation::DistanceFromPoint(const Vec3f& p )
	{
		return m_d - DotProduct(p, m_normal); 
	}

	float PlaneEquation::DistanceToLineSeg(const LineSeg3& a)
	{
		float aDistance = DistanceFromPoint(a.GetStart());
		float bDistance = DistanceFromPoint(a.GetEnd());

		if (aDistance > 0.0f && bDistance > 0.0f || aDistance < 0.0f && bDistance < 0.0f)
		{
			// this is a terniary operator which means
			// aDistance > bDistance == if (aDistance < bDistance)  
			// ? aDistance == { return aDistance; }
			// : == else 
			// bDistance == { return  bDistance; }
			return aDistance > bDistance ? aDistance : bDistance; 
		}
	}
}