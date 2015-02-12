#include "IdleState.h"


namespace Engine
{
	const char* IdleState::GetName() const
	{
		return "idle";
	}

	//void IdleState::Update()
	//{
	//	m_npc->SetVelocity(Vec3f(0, 0, 0));

	//	AIState::Update();
	//	if (m_time > 5)
	//	{
	//		m_npc->Decide();
	//	}
	//}
}