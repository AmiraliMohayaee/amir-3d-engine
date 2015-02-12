#include "Npc.h"
#include <iostream>
#include <assert.h>

namespace Engine
{
	void Npc::AddState(AIState* ai)
	{
		ai->SetNpc(this);
		m_aiStates.push_back(ai);
	}

	void Npc::Update()
	{
		RidgidBodyGO::Update();
		assert(m_aiState);
		m_aiState->Update();
	}

	void Npc::SetVelocity(Vec3f newVel)
	{
		newVel = RidgidBodyGO::GetVel();
	}

	void Npc::Decide()
	{
		float highestRank = -1;
		PAIState bestSoFar;

		// using default C++ iterators instead of 
		// the below C++11 autos example
		//for (AIStates::iterator it = m_aiStates.begin();
		//	it != m_aiStates.end();
		//	++it)
		//{
		//	AIState* ai = *it;
		//	float rank = ai->GetRank();
		//}


		// C++11 auto range for loop
		for (auto ai : m_aiStates)
		{
			float rank = ai->GetRank();
			if (rank > highestRank)
			{
				highestRank = rank;
				bestSoFar = ai;
			}
		}

		m_aiState = bestSoFar;
		std::cout << "Changing state to " << m_aiState->GetName()
			<< " (Rank was " << highestRank << ")\n";
	}
}