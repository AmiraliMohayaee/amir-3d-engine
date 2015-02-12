#ifndef SIMPLE_COLLISION_SYSTEM_H
#define SIMPLE_COLLISION_SYSTEM_H

#include "CollisionSystem.h"

namespace Engine
{
	class SimpleCollisionSystem: public CollisionSystem
	{
	public:
		virtual void Update(RidgidBodyObjects*);

	};
}

#endif