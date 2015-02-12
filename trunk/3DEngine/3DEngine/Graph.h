#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include "GraphEdge.h"
#include "GraphNode.h"
#include "MyGL.h"
#include <algorithm>


namespace Engine
{

	//struct GNCompare
	//{
	//	bool operator()(const GraphNode& gn1, const GraphNode& gn2)
	//	{
	//		return (gn1.GetID() < gn2.GetID());
	//	}
	//};

	//typedef std::map<GraphNode, EdgeList, GNCompare> NodeMap;

	typedef std::list<GraphEdge> EdgeList;
	typedef std::vector<GraphNode> GraphNodes;
	typedef std::vector<EdgeList> EdgeLists;

	typedef std::deque<int> Trail;

	class Graph
	{
	public:
		enum ColorFlag { VISITIED, NOTVISITED };

		Graph(): m_nextId(0) {}

		void AddNode(const GraphNode& node);
		void AddEdge(const GraphEdge& edge);
		GraphNode* GetNode(int id);  // const
		const EdgeList& GetEdgeList(int id) const;

		bool IsEdgePresent(int from, int to) const;

		int GetNumNodes() const;
		int GetNumAcitveNodes() const;
		int GetNumEdges() const;

		void SetTrail(Trail trail)
		{
			m_trail = trail;

			// Setting the correct colour for all relevant nodes in the graph
			for (auto it = m_trail.begin();
				it != m_trail.end();
				++it)
			{
				if (it == m_trail.begin())
				{
					m_nodes[*it].SetColour(1.0f, 1.0f, 1.0f, 1.0f);
					continue;
				}
				if (it == (m_trail.end() - 1))
				{
					m_nodes[*it].SetColour(1.0f, 0.0f, 0.0f, 1.0f);
					continue;
				}
				m_nodes[*it].SetColour(0.0f, 1.0f, 1.0f, 1.0f);
			}
		}

	/*	void SetColor(int id)
		{
			int c = std::count(m_trail.begin(), m_trail.end(), id);
			if (c)
			{
				glColor3f(1.0, 1.0, 1.0);
			}
			else
			{
				glColor3f(0.0, 1.0, 1.0);
			}
		}*/

		void SetEdgeColor(int id)
		{
			// set the edge colors by getting the to and from nodes connecting the edge
			//EdgeList edges;

			//int c = std::count(edges.begin(), edges.end(), id);

			////EdgeList& edge = *it;
			////GraphNode& node1 = m_nodes[edge.GetTo()];
			////GraphNode& node2 = m_nodes[edge.GetFrom()];

			//if (c)
			//{
			//	glColor3f(1.0, 0.0, 0.0);
			//}
			//else
			//{
			//	glColor3f(0.0, 0.0, 1.0);
			//}
		}

		void Draw();


	private:
		typedef std::map<int, EdgeList> EdgeMap;
		typedef std::map<int, GraphNode> NodeMap;

		NodeMap m_nodes;
		EdgeMap m_edges;

		int m_nextId;

		Vec3f m_pos;

		Trail m_trail;
	};
}

#endif