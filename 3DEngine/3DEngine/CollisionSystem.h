#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "RidgidBodyGO.h"
#include "Box3D.h"

namespace Engine
{
	class CollisionSystem
	{
	public:
		virtual ~CollisionSystem() {}

		virtual void Update(GameObjects*) = 0;

		bool TheyCollide(RidgidBodyGO* g1, RidgidBodyGO* g2)
		{
			//return Intersects(
			//	g1->GetRectangle(), g2->GetRectangle());

			return g1->GetModel().
				Intersects(g2->GetModel());
		}
	};
}

#endif