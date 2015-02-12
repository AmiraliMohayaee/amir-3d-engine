#include "Graph.h"
#include <assert.h>

namespace Engine
{

	void Graph::AddNode(const GraphNode& node)
	{
		m_nodes[node.GetID()] = node;
	}

	void Graph::AddEdge(const GraphEdge& edge)
	{
		m_edges[edge.GetFrom()].push_back(edge);
		//m_map[GraphNode(edge.GetFrom())].push_back(edge);
	}

	GraphNode* Graph::GetNode(int id)// const
	{
		return &m_nodes[id];
	}

	const EdgeList& Graph::GetEdgeList(int id) const
	{
		EdgeMap::const_iterator it = m_edges.find(id);
		assert(it != m_edges.end());
		return it->second;
	}

	void Graph::Draw()
	{
		for(NodeMap::iterator it = m_nodes.begin();
			it != m_nodes.end();
			it++)
		{
			GraphNode& node = it->second;
			//SetColor(it->first);

			node.Draw();
		}

		for(EdgeMap::iterator it = m_edges.begin();
			it != m_edges.end();
			it++)
		{
			EdgeList& edges = it->second;
			SetEdgeColor(it->first);

			for (EdgeList::iterator jt = edges.begin(); jt != edges.end(); ++jt)
			{
				GraphEdge& edge = *jt;

				GraphNode& node1 = m_nodes[edge.GetTo()];
				GraphNode& node2 = m_nodes[edge.GetFrom()];

				

				glBegin(GL_LINES);
				Vec3f v1 = node1.GetPos();
				Vec3f v2 = node2.GetPos();

				glVertex3f(v1.x, v1.y, v1.z);
				glVertex3f(v2.x, v2.y, v2.z);

				glEnd();
			}
		}
	}

	//bool Graph::IsEdgePresent(int from, int to) const
	//{
	//
	//
	//}
	//
	//int Graph::GetNumNodes() const
	//{
	//
	//}
	//
	//int Graph::GetNumAcitveNodes() const
	//{
	//
	//}
	//
	//int Graph::GetNumEdges() const
	//{
	//
	//}

}