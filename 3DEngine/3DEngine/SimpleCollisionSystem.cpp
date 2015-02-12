#include "CollisionSystem.h"
#include "SimpleCollisionSystem.h"
#include "RidgidBodyGO.h"
#include "Game.h"

void Engine::SimpleCollisionSystem::Update(RidgidBodyObjects* pObjs)
{
	for (RidgidBodyObjects::iterator it = pObjs->begin();
		it != pObjs->end();
		++it)
	{
		RidgidBodyObjects::iterator jt = it;
		++jt;
		for ( ; jt != pObjs->end(); ++jt)
		{
			if (TheyCollide(it->second, jt->second))
			{
				TheGame::Instance()->
					HandleCollision(it->second, jt->second);
			}
		}
	}
}