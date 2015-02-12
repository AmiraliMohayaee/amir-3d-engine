#ifndef FLEE_H_INCLUDED
#define FLEE_H_INCLUDED

#include "SteeringBehaviour.h"
#include "Vec3.h"

namespace Engine
{
	class Flee : public SteeringBehaviour
	{
		void OnFlee(Vec3f target, float force, float speed);
		void FleeSpeed();

	private:
		Vec3f m_target;
	};
}

#endif