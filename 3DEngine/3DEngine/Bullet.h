#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "btBulletDynamicsCommon.h"

namespace Engine
{
	class Bullet
	{
	public:
		Bullet();
		void BulletCollisionCheck(GameObject* go1, 
			GameObject* go2);

		bool BulletIsColliding();


	private:
		GameObject* m_go1;
		GameObject* m_go2;
	};
}


#endif