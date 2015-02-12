#ifndef ARRIVE_H_INCLUDED
#define ARRIVE_H_INCLUDED

#include "SteeringBehaviour.h"
#include "Seek.h"
#include "Agent.h"

namespace Engine
{
	class Arrive : public SteeringBehaviour
	{
	public:
		void OnArrival(Vec3f target, float force, float speed);
		void ArrivalSpeed();

	private:
		Vec3f m_target;

	};
}

#endif