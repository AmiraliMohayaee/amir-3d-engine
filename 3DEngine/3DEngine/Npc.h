#pragma once

#include "SmartPointer.h"
#include "AIState.h"
#include <vector>
#include "RidgidBodyGO.h"

namespace Engine
{
	class AIState;

	class Npc : public RidgidBodyGO
	{
	public:
		Npc() : m_aiState(nullptr) {}
		void Decide();
		void AddState(AIState* ai);
		
		virtual void Update() override;
		void SetVelocity(Vec3f newVel);


	private:
		typedef std::vector<PAIState> AIStates;
		AIStates m_aiStates;

		AIState* m_aiState;
	};
}