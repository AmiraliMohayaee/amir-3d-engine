#ifndef GRAPH_EDGE_H_INCLUDED
#define GRAPH_EDGE_H_INCLUDED

#include "Vec2.h"


namespace Engine
{
	class GraphEdge
	{
	public:
		GraphEdge(int from, int to, float cost)
		{
			m_from = from; 
			m_to = to; 
			m_cost = cost;
		}

		float GetCost() const { return m_cost; }

		int GetTo() const { return m_to; }
		int GetFrom() const { return m_from; }

		//const void* EdgeSet() const;
		//int SetEdge(int id) { m_id = id; }

		void Draw() {}


	private:
		float m_cost;
		int m_from;
		int m_to;

	};
}

#endif