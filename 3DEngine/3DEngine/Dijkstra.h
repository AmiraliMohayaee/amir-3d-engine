#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <iostream>
#include "BreadthFirstSearch.h"
#include <map>
#include <queue>
#include "Graph.h"
#include "NodePriorityQueue.h"


namespace Engine
{
	typedef std::map<int, int> BreadCrumbs;
	//typedef std::queue<int> ThePath;

	class Dijkstra
	{
	public:
		bool DijkstraSerach(Graph& graph, int startNodeId, int endNodeId, Trail& thePath)
		{
			Costs costs;
			Cost c;
			NodePriorityQueue priorityQueue(&costs);
			std::set<int> visited;
			//std::stack<int> nodes;

			c.gCost = 0;
			c.hCost = 0;
			c.fCost = c.gCost + c.hCost;


			//ThePath thePath;
			BreadCrumbs breadCrumbs;
			costs [startNodeId] = c;

			priorityQueue.Push(startNodeId);

			//graph.GetNode(startNodeId);

			while (!priorityQueue.IsEmpty())
			{
				// Get top node and pop it
				int node = priorityQueue.Top();
				priorityQueue.Pop();

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

					c.gCost = costs[node].gCost + edge.GetCost();

					if (visited.count(otherEnd) == 0)
					{
						costs[otherEnd] = c;
						visited.insert(otherEnd);
						priorityQueue.Push(otherEnd);
						breadCrumbs[otherEnd] = node;
					}
					else if (costs[otherEnd].gCost > c.gCost)
					{
						costs[otherEnd] = c;
					}
				}

				priorityQueue.ReSort();

				
			}
			// Stack empty - no path
			return false;
		}


	private:
		//Nodes node;1c
	};
}


#endif