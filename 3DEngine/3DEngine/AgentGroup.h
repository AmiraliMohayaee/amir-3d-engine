#ifndef AGENT_GROUP_H_INCLUDED
#define AGENT_GROUP_H_INCLUDED

#include <vector>
#include "Agent.h"


namespace Engine
{
	class AgentGroup
	{
	public:
		void AddAgent(Agent*);
		Agents GetNeighbours(Agent*, float redius) const;


	private:
		Agents m_agents;

	};

	typedef std::vector<Agent*> Agents;
}

#endif