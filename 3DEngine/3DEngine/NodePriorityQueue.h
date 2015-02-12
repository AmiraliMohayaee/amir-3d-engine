#ifndef NODE_PRIORITY_QUEUE_H_INCLUDED
#define NODE_PRIORITY_QUEUE_H_INCLUDED

#include <vector>
#include <map>


namespace Engine
{
	struct Cost
	{
		float fCost;
		float gCost;
		float hCost;
	};

	typedef std::map<int, Cost> Costs;
	
	class NodePriorityQueue
	{
	public:
		NodePriorityQueue(Costs* costs) : m_costs(costs) {}

		int Top() const;
		void Pop();
		void Push(int);
		bool IsEmpty() const;
		void ReSort();
		bool Find(int node) const;


	private:
		Costs* m_costs;

		typedef std::vector<int> Nodes;
		Nodes m_nodes;
	};
}

#endif