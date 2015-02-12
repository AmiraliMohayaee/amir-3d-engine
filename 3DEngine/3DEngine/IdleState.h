#pragma once

#include "AIState.h"
#include "Npc.h"


namespace Engine
{
	class IdleState: public AIState, public Npc
	{
	public:
			virtual const char* GetName() const override;
			virtual void Update() override;


	private:
		Npc* m_npc;
	};

}