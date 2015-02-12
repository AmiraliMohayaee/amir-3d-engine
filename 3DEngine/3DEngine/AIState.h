#pragma once 

#include "SmartPointer.h"



namespace Engine
{
	class GameObject;
	class Npc;
	class AIState;

	// Base AI class for AI states
	class AIState : public RefCounted
	{
	public:
		public:
		AIState() : m_npc(), m_target(0), m_time(0), m_rank(0) {}
		// Each subclass type has a uniqe name
		virtual const char* GetName() const = 0;
		// Updates timer
		virtual void Update() = 0;
		// Resets timer
		virtual void OnActivated() { m_time = 0; }
		virtual void OnDeactivated() {}
		// Return float - higher means this AI is better
		virtual float GetRank() { return m_rank; }
		void SetNpc(Npc* npc) { m_npc = npc; }
		// Most AI behaviours involve some other target, e.g. to chase or avoid
		void SetTarget(GameObject* target) { m_target = target; }

	protected:
		Npc* m_npc;
		GameObject* m_target;
		float m_time; // time since activated
		float m_rank; // default rank
	};

	typedef SmartPointer<AIState> PAIState;

	// Alternatively typedef AIState* PAIState;
}