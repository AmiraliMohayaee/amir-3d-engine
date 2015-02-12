#ifndef STEERING_BEHAVIOUR_H
#define STEERING_BEHAVIOUR_H

#include "Vec3.h"

namespace Engine
{
	class Agent;

	class SteeringBehaviour
	{
	public:
		virtual ~SteeringBehaviour() = 0 {}
		virtual void Update(Agent* parent, Vec3f* force) = 0;
		virtual const char* GetTypeName() const = 0;

	private:
		Agent* m_agent;
		Agent* m_target;
	};
}

#endif