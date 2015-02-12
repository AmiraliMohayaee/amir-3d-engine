#include "OBB3.h"
#include "MyGL.h"



namespace Engine
{
	// Todo: Change function return type and test later
	Vec3f OBB3::Centre(const OBB3& bb)
	{
		float x = (m_minVec.x + m_maxVec.x) / 2.0f;
		float y = (m_minVec.y + m_maxVec.y) / 2.0f;
		float z = (m_minVec.z + m_maxVec.z) / 2.0f;

		return Vec3f(x, y, z);
	}

	//OBB3 OBB3::Set(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax) const
	//{
	//	float xmin = m_minVec.x, xmax = m_maxVec.x, ymin = m_minVec.y, ymax = m_maxVec.y, zmin = m_minVec.z, zmax = m_maxVec.z;

	//	return OBB3(Vec3f(xmin, ymin, zmin), Vec3f(xmax, ymax, zmax));
	//}

	//Vec3f OBB3::Extend()
	//{

	//}


	bool OBB3::Intersects(const OBB3& otherBox) const
	{	
		return(
			m_maxVec.x > otherBox.m_minVec.x && otherBox.m_maxVec.x > m_minVec.x &&
			m_maxVec.y > otherBox.m_minVec.y && otherBox.m_maxVec.y > m_minVec.y &&
			m_maxVec.z > otherBox.m_minVec.z && otherBox.m_maxVec.z > m_minVec.z);
	}


	// Debug function for testing the class
	void DrawOBBLine(const Vec3f& v1, const Vec3f& v2)
	{
		  glBegin(GL_LINES);
			  glVertex3f(v1.x, v1.y, v1.z);
			  glVertex3f(v2.x, v2.y, v2.z);
		  glEnd();
	}


	// Debug function for testing the class
	void OBB3::Draw() const
	{
		DrawOBBLine(Vec3f(m_minVec.x, m_minVec.y, m_minVec.z), 
						(Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z)));	//1

		DrawOBBLine(Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z), 
						Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z));		//2

		DrawOBBLine(Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z), 
						Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z));		//3

		DrawOBBLine(Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z), 
						Vec3f(m_minVec.x, m_minVec.y, m_minVec.z));		//4

		DrawOBBLine(Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z), 
						Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z));		//5

		DrawOBBLine(Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z), 
						Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z));		//6

		DrawOBBLine(Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z), 
						Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z));		//7

		DrawOBBLine(Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z), 
						Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z));		//8

		DrawOBBLine(Vec3f(m_minVec.x, m_minVec.y, m_minVec.z), 
						Vec3f(m_minVec.x, m_maxVec.y, m_minVec.z));		//9

		DrawOBBLine(Vec3f(m_maxVec.x, m_minVec.y, m_minVec.z), 
						Vec3f(m_maxVec.x, m_maxVec.y, m_minVec.z));		//10

		DrawOBBLine(Vec3f(m_maxVec.x, m_minVec.y, m_maxVec.z), 
						Vec3f(m_maxVec.x, m_maxVec.y, m_maxVec.z));		//11

		DrawOBBLine(Vec3f(m_minVec.x, m_minVec.y, m_maxVec.z), 
						Vec3f(m_minVec.x, m_maxVec.y, m_maxVec.z));		//12
	}


	bool OBB3::Contains(const Vec3f& v) const
	{
		return (
			v.x >= m_minVec.x && v.x < m_maxVec.x &&
			v.y >= m_minVec.y && v.y < m_maxVec.y &&
			v.z >= m_minVec.z && v.z < m_maxVec.z
		);
	}
}