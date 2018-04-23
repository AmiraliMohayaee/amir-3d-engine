#include "DepthFirstSearchTest.h"


namespace Engine
{
		DepthFirstSearchTest::DepthFirstSearchTest()
		{

		}

		DepthFirstSearchTest::~DepthFirstSearchTest()
		{

		}


		bool DepthFirstSearchTest::DFSearch(Graph& graph, int startNodeId, int endNodeId)
		{
			std::set<int> visited;
			std::stack<int> nodes;
			std::map<int, int> breadCrumbs;

			// Push start node onto stack
			graph.GetNode(startNodeId);

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
					//thePath = CreateTrail(startNodeId, endNodeId, breadCrumbs);
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

				// Stack empty - no path
				return false;
			}
 		}

		void Draw()
		{
			while (true)
			{
				// Draw graphs
				// do pathfinding
				// Set trail
				// 
			}
		}

		void Update()
		{
			// Call the pathfinding algorithm

		}




}