#ifndef DEPTH_FIRST_SEARCH_H_INCLUDED
#define DEPTH_FIRST_SEARCH_H_INCLUDED

#include <iostream>
#include "Graph.h"
#include "GraphNode.h"
#include "GraphEdge.h"
#include <set>
#include <stack>
#include <map>
#include <assert.h>


namespace Engine
{
	typedef std::deque<int> Trail;
	typedef std::map<int, int> BreadCrumbs;

	Trail CreateTrail(int start, int end, BreadCrumbs& breadcrumbs)
	{
		Trail result;
		int node = end;
		do 
		{
			result.push_front(node);
			node = breadcrumbs[node];
			//assert(node);
		} 
		while (node != start);

		result.push_front(start);

		return result;
	}

	class DepthFirstSearch
	{
	public:
		bool Dfs(Graph& graph, int startNodeId, int endNodeId, Trail& thePath)
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
	};
}


#endif