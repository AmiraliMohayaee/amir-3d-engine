#ifndef BREADTH_FIRST_SEARCH_H_INCLUDED
#define BREADTH_FIRST_SEARCH_H_INCLUDED

#include <iostream>
#include "Graph.h"
#include "GraphNode.h"
#include "GraphEdge.h"
#include <set>
#include <queue>
#include <map>
#include <assert.h>
#include "DepthFirstSearch.h"


namespace Engine
{
	typedef std::map<int, int> BreadCrumbs;


	class BreadthFirstSearch
	{
	public:
		bool Bfs(Graph& graph, int startNodeId, int endNodeId, Trail& thePath)
		{
			std::set<int> visited;
			std::stack<int> nodes;
			std::map<int, int> breadCrumbs;

			// Push start node onto stack
			graph.GetNode(startNodeId);

			nodes.push(startNodeId);

			while (!nodes.empty())
			{
				// Get top node and pop it
				int node = nodes.top();
				nodes.pop();

				// Marked as visited
				visited.insert(node);

				// Checking if this is our target
				if (node == endNodeId)
				{
					thePath = CreateTrail(startNodeId, endNodeId, breadCrumbs);
					return true;
				}

				// Get list of edges
				EdgeList edgeList = graph.GetEdgeList(node);

				// For each Edge, 
				for (EdgeList::iterator it = edgeList.begin();
					it != edgeList.end();
					it++)
				{
					// if not already visited, push onto stack and mark as visited
					GraphEdge edge = *it;
					int otherEnd = edge.GetTo();

					if (visited.count(otherEnd) == 0)
					{
						visited.insert(otherEnd);
						nodes.push(otherEnd);
						breadCrumbs[otherEnd] = node;
					}
				}
			}

			return false;
		}

	private:
		Graph m_graph;
		int m_target;
		int m_id;

	};
}

#endif