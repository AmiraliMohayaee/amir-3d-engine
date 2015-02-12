#include "Box3D.h"
#include "MyGL.h"
#include <assert.h>


namespace Engine
{
	bool Box3D::Intersects(const Box3D& otherBox) const
	{	
		//static collision detection
		return(
			m_maxVec.x > otherBox.m_minVec.x && otherBox.m_maxVec.x > m_minVec.x &&
			m_maxVec.y > otherBox.m_minVec.y && otherBox.m_maxVec.y > m_minVec.y &&
			m_maxVec.z > otherBox.m_minVec.z && otherBox.m_maxVec.z > m_minVec.z);
	}

	// Debug function for testing the class
	void DrawLine(const Vec3f& v1, const Vec3f& v2)
	{
		  glBegin(GL_LINES);
			  glVertex3f(v1.x, v1.y, v1.z);
			  glVertex3f(v2.x, v2.y, v2.z);
		  glEnd();
	}

	// Debug function for testing the class
	void Box3D::Draw() const
	{
		  DrawLine(Vec3f(m_minVec.x, m_minVec.y, m_minVec.z), 
						   (Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z)));	//1

		  DrawLine(Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z), 
						   Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z));		//2

		  DrawLine(Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z), 
						   Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z));		//3

		  DrawLine(Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z), 
						   Vec3f(m_minVec.x, m_minVec.y, m_minVec.z));		//4

		  DrawLine(Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z), 
						   Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z));		//5

		  DrawLine(Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z), 
						   Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z));		//6

		  DrawLine(Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z), 
						   Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z));		//7

		  DrawLine(Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z), 
						   Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z));		//8

		  DrawLine(Vec3f(m_minVec.x, m_minVec.y, m_minVec.z), 
						   Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z));		//9

		  DrawLine(Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z), 
						   Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z));		//10

		  DrawLine(Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z), 
						   Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z));		//11

		  DrawLine(Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z), 
						   Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z));		//12
	}

	// Related to making Octree Component/Leaf nodes
	Box3D Box3D::MakeOctreeChild(int octant) const
	{
		assert(octant < 8);

		// Centre of box
		float cx = (m_minVec.x + m_maxVec.x) / 2.0f;
		float cy = (m_minVec.y + m_maxVec.y) / 2.0f;
		float cz = (m_minVec.z + m_maxVec.z) / 2.0f;

		float xmin = m_minVec.x, xmax = m_maxVec.x, ymin = m_minVec.y, ymax = m_maxVec.y, zmin = m_minVec.z, zmax = m_maxVec.z;
		
		if (octant & 1)
		{
			xmin = cx;
		}
		else
		{
			xmax = cx;
		}
		if (octant & 2)
		{
			ymin = cy;
		}
		else
		{
			ymax = cy;
		}
		if (octant & 4)
		{
			zmin = cz;
		}
		else
		{
			zmax = cz;
		}

		return Box3D(Vec3f(xmin, ymin, zmin), Vec3f(xmax, ymax, zmax));
	}

	bool Box3D::Contains(const Vec3f& v) const
	{
		return (
			v.x >= m_minVec.x && v.x < m_maxVec.x &&
			v.y >= m_minVec.y && v.y < m_maxVec.y &&
			v.z >= m_minVec.z && v.z < m_maxVec.z
		);
	}
}