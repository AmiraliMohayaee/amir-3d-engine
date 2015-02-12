#pragma once

#include "Agent.h"
#include "AgentGroup.h"
#include "AIState.h"
#include <vector>
#include <list>

namespace Engine
{
	class TeaPot : public Agent
	{
	public:
		TeaPot();
		//Teapot(pos) : m_position(pos), 
		~TeaPot();

		void AddTeaPot(const TeaPot& pot)
		{
			TeaPotList.push_front(pot);
		}


	private:
		Vec3f m_pos;
		float m_mass;
		float m_maxSpeed;
		float m_maxForce;
		float m_maxTurnRate; 
	};

	typedef std::vector<TeaPot*> TheTeaPots;
	typedef std::list<TeaPot*> TeaPotList;
}