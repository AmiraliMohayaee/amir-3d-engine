#ifndef A_STAR_H_INCLUDED
#define A_STAR_H_INCLUDED

#include <iostream>
#include "BreadthFirstSearch.h"
#include <map>
#include <queue>
#include <algorithm>
#include "Graph.h"
#include "NodePriorityQueue.h"
#include "Dijkstra.h"

namespace Engine
{
	typedef std::map<int, int> BreadCrumbs;

	class AStar
	{
	public:
		AStar()
		{
			m_fCost = 0.0f;
			m_hCost = 0.0f;
			m_gCost = 0.0f;
		}

		void SetGCost();
		void SetFCost();

		void Estimate(GraphNode& first, GraphNode& last)
		{
			// Estimate the cost from first to last node
			// Get the absolute value of each component, except the y-axis
			Vec3f heuVec = last.GetPos() - first.GetPos();
			m_hCost = std::abs(heuVec.x) + std::abs(heuVec.z);
		}

		bool AStarSearch(Graph& graph, int startNodeId, int endNodeId, Trail& thePath)
		{
			Costs costs;	// F cost
			NodePriorityQueue priorityQueue(&costs);	// Open node List
			std::set<int> visited;	// Closed nodes List
			//std::stack<int> nodes;

			// Aquiring the H cost
			Estimate(*graph.GetNode(startNodeId), *graph.GetNode(endNodeId));

			// F(Cost) = G(Accumulative cost)  +  H (cost to target)
			Cost cost;
			cost.gCost = 0;
			cost.hCost = m_hCost;
			cost.fCost = cost.gCost + cost.hCost;

			BreadCrumbs breadCrumbs;	// Used for finding the path
			costs [startNodeId] = cost;	// Assigning to node cost

			priorityQueue.Push(startNodeId);

			//graph.GetNode(startNodeId);

			while (!priorityQueue.IsEmpty())
			{
				// Get top node and pop it
				int node = priorityQueue.Top();
				priorityQueue.Pop();

				// Marked as visited/Open
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

					Estimate(*graph.GetNode(otherEnd), *graph.GetNode(endNodeId));

					//float cost = costs[node] + edge.GetCost();
					Cost currentCost;
					currentCost.gCost = costs[node].gCost + edge.GetCost();
					currentCost.hCost = m_hCost;
					currentCost.fCost = currentCost.gCost + currentCost.hCost;

					// Pushing the node in the visited list into the breadcrumbs
					breadCrumbs[otherEnd] = node;

					// If the current node is in the open list, we'd want
					// check the fcost coming from the previous parent
					// 
					// if not, then we would want to add this to the open list
					// and assign a cost to it
					if (priorityQueue.Find(otherEnd))
					{
						if (currentCost.gCost < costs[otherEnd].gCost) 
						{
							breadCrumbs[otherEnd] = node;
							costs[otherEnd] = currentCost;
							priorityQueue.ReSort();
						}
					}
					else
					{
						costs[otherEnd] = currentCost;
						priorityQueue.Push(otherEnd);
						priorityQueue.ReSort();
					}
				}

				///priorityQueue.ReSort();
			}

			return false;
		}


	private:
		float m_fCost;
		float m_gCost;
		//Heuristics m_gCost;
		float m_hCost;
	};

}

#endif




					//if (visited.count(otherEnd) == 0)
					//{
					//	costs[otherEnd] = cost;
					//	visited.insert(otherEnd);
					//	//nodes.push(otherEnd);
					//	breadCrumbs[otherEnd] = node;
					//}
					//else if (costs[otherEnd] > cost)
					//{
					//	costs[otherEnd] = cost;
					//}