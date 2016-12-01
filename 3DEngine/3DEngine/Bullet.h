#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "btBulletDynamicsCommon.h"
#include "RidgidBodyGO.h"

namespace Engine
{
	class Bullet
	{
	public:
		Bullet();
		void BulletCollisionCheck(RidgidBodyGO* go1, 
			RidgidBodyGO* go2);

		bool BulletIsColliding();


	private:
		RidgidBodyGO* m_go1;
		RidgidBodyGO* m_go2;
	};
}


#endif