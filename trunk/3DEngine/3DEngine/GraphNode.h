#ifndef GRAPH_NODE_H_INCLUDED
#define GRAPH_NODE_H_INCLUDED

#include "Vec2.h"
#include "Vec3.h"
#include "GameObject.h"
#include "MyGL.h"

namespace Engine
{
	class GraphNode
	{
	public:
		GraphNode(int id = -1)
		{
			m_data = 0;
			m_id = id;
			m_colour[0] = 0.5f;
			m_colour[1] = 0.5f;
			m_colour[2] = 0.5f;
			m_colour[3] = 1.0f;
		}

		int GetID() const { return m_id; }
		int SetID(int id) { m_id = id; }

		void SetPos(Vec3f pos)
		{
			m_pos = pos;
		}

		const Vec3f& GetPos() const { return m_pos; }

		void Draw()
		{
			glPushMatrix();
				glColor4fv(m_colour);
				glTranslatef(m_pos.x, m_pos.y, m_pos.z);
				glutSolidCube(0.5f);
			glPopMatrix();
		}

		void SetColour(float r, float g, float b, float a)
		{
			m_colour[0] = r;
			m_colour[1] = g;
			m_colour[2] = b;
			m_colour[3] = a;
		}

		const float* GetColour() const
		{
			return m_colour;
		}

		//bool opertator<(const GraphNode& other) const
		//{
		//	retrun (m_id < other.m_id);
		//}

	private:
		int m_id;
		void* m_data;
		Vec3f m_pos;
		float m_colour[4];
	};
}

#endif