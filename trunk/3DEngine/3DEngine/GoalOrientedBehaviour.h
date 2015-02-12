#ifndef GOAL_ORIENTED_BEHAVIOUR_H
#define GOAL_ORIENTED_BEHAVIOUR_H

#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include "Agent.h"

namespace Engine
{
	class GoalOrientedBehaviour
	{
	private:
		int m_weight;

	public:
		GoalOrientedBehaviour();
		~GoalOrientedBehaviour();

		typedef std::vector<int> Goals;
		typedef std::vector<int> GoalCosts;
		typedef std::map<Agent, std::string> Needs;
		

		bool IsSatisfied(Goals goal);
		bool MakePlan();
	};
}

#endif