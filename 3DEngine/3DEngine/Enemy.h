#ifndef ENEMY_H
#define ENEMY_H

#include "RidgidBodyGO.h"
#include "TextureManager.h"
#include "Billboard.h"
#include "CollisionMesh.h"
#include "Player.h"
#include "Box3D.h"

namespace Engine
{
	class Enemy : public RidgidBodyGO
	{
	public:
		Enemy();
		// We're definitely going to need this
		// well...the object factory will anyway
		~Enemy();
		virtual void Draw();
		void Load();
		virtual void Update();
		void AIApproach();
		void AIAttack();
		void AIIdle();
		void Pain();
		void DeadState();

		void SetPlayer(Player*);

		virtual const char* GetTypeName() const;

		bool IsEnemyDead(){return m_isEnemyDead;}

	private:
		bool m_isEnemyDead;
		TextureManager m_texture[2];
		Billboard m_bill;
		int m_currentTex;
		float m_time;
		Player* m_player;

		Box3D m_enemyBox;
	};
}

#endif