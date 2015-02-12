#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include "Graph.h"
#include <deque>
#include <map>
#include <list>
#include "NodePriorityQueue.h"
#include <functional>

namespace Engine
{
	typedef std::deque <unsigned int> Path;
	typedef std::function <float (unsigned int, unsigned int, const Graph&)> HFunction;

	namespace 
	{
		typedef std::map <unsigned int, unsigned int> PathMap;
	}

	bool DepthFirstSearch(const Graph& graph, unsigned int from, unsigned int to, Path* path);
	bool BreadthFirstSearch(const Graph& graph, unsigned int from, unsigned int to, Path* path);
	bool AStar(const Graph& graph, unsigned int from, unsigned int to, Path* path, HFunction hFunc);
}

#endif