#include "Enemy.h"
#include "Timer.h"
#include "SoundManager.h"
#include "Game.h"
#include "LossState.h"
#include "MyGL.h"

namespace Engine
{
	Enemy::Enemy()
	{
		//m_pos = (1.0f, 1.0f, 1.0f);

		const int MAX_SIZE = 100.0f;
		m_pos = Engine::Vec3f(rand() % MAX_SIZE - MAX_SIZE/2, 0, rand() % MAX_SIZE - MAX_SIZE/2);

		m_currentTex = 0;
		m_time = 0;

		m_player = 0;

		m_isEnemyDead = false;
	}

	Enemy::~Enemy()
	{

	}

	void Enemy::Load()
	{
		m_texture[0].Load("assets/images/textures/DoomZombieSgt_Walk1.png");
		m_texture[1].Load("assets/images/textures/DoomZombieSgt_Walk2.png");
		m_texture[2].Load("assets/images/textures/DoomZombieSgt_Walk3.png");
	}

	void Enemy::Draw()
	{
		if (m_isEnemyDead)
		{
			return;
		}

		m_texture[m_currentTex].Draw();

		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(m_pos.x, m_pos.y, m_pos.z);
		glutWireCube(1.0f);
		glPopMatrix();

		// The position and scale of the billboard
		m_bill.Draw(m_pos, 1.5f);
	}

	void Enemy::Update()
	{
		if (m_isEnemyDead)
		{
			return;
		}

		m_time += Timer::Instance()->GetDt();

		if (m_time > 0.3f)
		{
			m_time = 0;
			++m_currentTex;

			if (m_currentTex > 2)
			{
				m_currentTex = 0;
			}
		}

		m_vel = m_player->GetPos() - m_pos;
		m_vel.Normalize();
		m_vel * 2.0f;


		m_enemyBox.m_minVec.x = m_pos.x - 0.5;
		m_enemyBox.m_maxVec.x = m_pos.x + 0.5;
		m_enemyBox.m_minVec.y= m_pos.y - 0.5;
		m_enemyBox.m_maxVec.y = m_pos.y + 0.5;
		m_enemyBox.m_minVec.z = m_pos.z - 0.5;
		m_enemyBox.m_maxVec.z= m_pos.z + 0.5;


		if (m_player->GetPlayerBounds().Intersects(m_enemyBox))
		{
			m_player->PlayerDamageTake();

			m_player->LoseHealth(40);

			if (m_player->GetHealth() <= 0)
			{
				TheGame::Instance()->SetGameState(TheLossState::Instance());
			}
		}

		RidgidBodyGO::Update();
	}

	// Pain() can act as a getter for the enemy health
	void Enemy::Pain()
	{

	}

	void Enemy::AIApproach()
	{

	}

	void Enemy::AIAttack()
	{

	}

	void Enemy::AIIdle()
	{

	}

	void Enemy::DeadState()
	{
		m_isEnemyDead = true;
	}

	const char* Enemy::GetTypeName() const
	{
		return ("Enemy");
	}

	void Enemy::SetPlayer(Player* p)
	{
		m_player = p;
	}
}