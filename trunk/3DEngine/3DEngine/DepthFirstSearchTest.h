#pragma once 

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
	class DepthFirstSearchTest
	{
	private:
		Graph m_graph;
		int m_target;

		typedef std::deque<int> Trail;
		typedef std::map<int, int> BreadCrumbs;


	public:
		DepthFirstSearchTest();
		~DepthFirstSearchTest();
		
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

		bool DFSearch(Graph& graph, int startNodeId, int endNodeId);

		void Draw();
		void Update();
	};
}