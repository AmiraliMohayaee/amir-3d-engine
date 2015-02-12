#include "NodePriorityQueue.h"
#include <assert.h>
#include <algorithm>

namespace Engine
{
	struct NodeOrder
	{
		NodeOrder(const Costs& costs) : m_costs(costs) {}

		bool operator()(int n1, int n2) const
		{
			assert(m_costs.find(n1) != m_costs.end());
			assert(m_costs.find(n2) != m_costs.end());

			// Cost cast hack
			Costs& costs = const_cast<Costs&>(m_costs);

			// We want the node with lowest total at the root of the heap, so we
			// need the opposite of 'less-than'
			return (costs[n1].fCost > costs[n2].fCost);
		}

	private:
		const Costs& m_costs;
	};

	int NodePriorityQueue::Top() const
	{
		return m_nodes.front();
	}

	void NodePriorityQueue::Pop()
	{
		std::pop_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
		m_nodes.pop_back();
	}

	void NodePriorityQueue::Push(int node)
	{
		m_nodes.push_back(node);
		std::push_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
	}

	void NodePriorityQueue::ReSort()
	{
		std::make_heap(m_nodes.begin(), m_nodes.end(), NodeOrder(*m_costs));
	}

	bool NodePriorityQueue::IsEmpty() const
	{
		return m_nodes.empty();
	}

	bool NodePriorityQueue::Find(int node) const
	{
		auto it = std::find(m_nodes.begin(), m_nodes.end(), node);
		if (it != m_nodes.end())
		{
			return true;
		}
		return false;
	}
}