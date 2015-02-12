#include "Player.h"
#include "Vec3.h"
#include "Timer.h"
#include "Room.h"
#include "Enemy.h"
#include "SoundManager.h"
#include "Game.h"
#include "WinState.h"
#include "LossState.h"
#include <math.h>

int c = c++;

namespace Engine
{
	Player::Player()
	{
		m_health = 0;
		m_armor = 0;
		m_keys = 0;
		m_score = 0;

		// Camera Position
		m_eyex = cos(c) * 10.0;
		m_eyey = 0;
		m_eyez = sin(c) * 10.0;  // Originally set to 20

		// Coords of where we're looking at
		m_centerx = 0;
		m_centery = 0;
		m_centerz = 0;

		// camera rotation
		m_upx = 0;
		m_upy = 1;
		m_upz = 0;

		m_heading = 0;

		for (int i = 0; i < 4; i++)
		{
			m_wasd[i] = false;
		}

		m_texture.Load("Assets/Images/textures/hud.png");
	}

	Player::~Player()
	{

	}

	void Player::Draw()
	{
		glEnable(GL_TEXTURE_2D);
		m_texture.Draw();
		//ThePlayer::Instance()->PlayerViewpoint();
		PlayerViewpoint();

		glPushMatrix();
		glTranslatef(m_pos.x, m_pos.y, m_pos.z);
		glutWireCube(1.0f);
		glPopMatrix();
	}

	void Player::Update()
	{
		Enemy enemy;

		float s = sin(m_heading);
		float c = cos(m_heading);

		Vec3f vHeading;
		if (m_wasd[0])
		{
			vHeading += Vec3f(c, 0, s);	//what direction you would use for bullets
		}

		if (m_wasd[1])
		{
			vHeading += Vec3f(s, 0, -c);
		}

		if (m_wasd[2])
		{
			vHeading += Vec3f(-c, 0, -s);
		}

		if (m_wasd[3])
		{
			vHeading += Vec3f(-s, 0, c);
		}

		// call 10 m_speed
		m_vel = vHeading * 10;


		RidgidBodyGO::Update();

		m_eyex = m_pos.x;
		m_eyey = m_pos.y;
		m_eyez = m_pos.z;

		m_centerx = m_eyex + c;
		m_centery = m_eyey;
		m_centerz = m_eyez + s;

		m_playerBox.m_minVec.x = m_pos.x - 0.5;
		m_playerBox.m_maxVec.x = m_pos.x + 0.5;
		m_playerBox.m_minVec.y= m_pos.y - 0.5;
		m_playerBox.m_maxVec.y = m_pos.y + 0.5;
		m_playerBox.m_minVec.z = m_pos.z - 0.5;
		m_playerBox.m_maxVec.z= m_pos.z + 0.5;

		if(GetHealth() <= 0)
		{
			TheGame::Instance()->SetGameState(TheLossState::Instance());
		}
	}

	void Player::PlayerViewpoint()
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(
			m_eyex, m_eyey, m_eyez, // camera pos
			m_centerx, m_centery, m_centerz,  // coordinations of where we're looking at
			m_upx, m_upy, m_upz);// Rotation
	}

	void Player::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_w)
		{
			m_wasd[0] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_a)
		{
			m_wasd[1] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_s)
		{
			m_wasd[2] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_d)
		{
			m_wasd[3] = (k.state == SDL_PRESSED);
		}

		//	&&  k.state == SDL_PRESSED)
		//{
		//	Capsule cap(LineSeg3(Vec3f(m_eyex, m_eyey, m_eyez), 
		//		Vec3f(m_eyex, m_eyey, m_eyez - 10.0f)), 1.0f);
		//	CollisionMesh::TriPtrs triptrs;
		//	if (!m_collMesh->Intersects(cap, &triptrs))
		//	{
		//		m_eyez -= 10.0f;
		//		m_centerz -= 10.0f;
		//	}
		//}

		//if (k.keysym.sym == SDLK_a
		//	&&  k.state == SDL_PRESSED)
		//{
		//	Capsule cap(LineSeg3(Vec3f(m_eyex, m_eyey, m_eyez), 
		//		Vec3f(m_eyex - 10.0f, m_eyey, m_eyez)), 1.0f);
		//	CollisionMesh::TriPtrs triptrs;
		//	if (!m_collMesh->Intersects(cap, &triptrs))
		//	{
		//		m_eyex -= 10.0f;
		//		//m_centerx -= 10.0f;
		//	}
		//}
	}

	void Player::OnMouseMotionEvent(const SDL_MouseMotionEvent& mm)
	{
		// Variable for rotating the camera
		static int oldx = mm.x;
		static int oldy = mm.y;
		int xdiff = mm.x - oldx;
		int ydiff = mm.y - oldy;
		oldx = mm.x;
		oldy = mm.y;

		// Value for setting the mouse sensitivity
		// "A damping value"
		oldx += (float)xdiff / 1000;
		oldy += (float)ydiff / 1000;

		float xrad = DegToRad(oldx);
		float yrad = DegToRad(oldy);

		m_heading = xrad;
	}

	void Player::CheckFire(const Tri& tri, const LineSeg3& line)
	{

	}

	void Player::OnMouseButtonEvent(const SDL_MouseButtonEvent& mb)
	{
		SoundManager sound;

		if((mb.button == 1) && (mb.state == SDL_PRESSED))
		{
			sound.PlaySound("Assets/sounds/DoomSounds/fire1.wav");

			float s = sin(m_heading);
			float c = cos(m_heading);

			// what direction you would use for bullets
			Vec3f vHeading = Vec3f(c, 0, s);
			// Mouse sensitivity
			vHeading *= 1000;
			LineSeg3 lineseg((vHeading + m_pos), m_pos);
			// Radius of the bullet
			float radius = 1.0f;
			float enemyRadius = 1.0f;
			float radSq = radius + enemyRadius;
			radSq *= radSq;
			// Capsule for detecting collision with bullet and player
			Capsule cap(lineseg, radius);
			CollisionMesh::TriPtrs triptrs;


			m_collMesh->Intersects(cap, &triptrs);
			float closestTriSq = 99999999.9f;
			for (unsigned int i = 0; i < triptrs.size(); i++)
			{
				float distSq = (triptrs[i]->Centre() - m_pos).SqrLength();
				if (distSq < closestTriSq)
				{
					closestTriSq = distSq;
				}
			}

			float closestEnemySq = 999999999.9f;
			Enemy* deadEnemy = 0;
			for (unsigned int i = 0; i < m_enemies.size(); i++)
			{
				const Vec3f enemyPos = m_enemies[i]->GetPos();
				float sqDist = lineseg.Range(enemyPos);
				float sqDistToUs = (enemyPos - m_pos).SqrLength();
				if (sqDist < radSq && sqDistToUs < closestEnemySq)
				{
					// You have hit this baddie if nothing else in the way
					deadEnemy = m_enemies[i];
					closestEnemySq = sqDistToUs;
				}
			}

			if (closestEnemySq < closestTriSq)
			{
				assert(deadEnemy);
				// Kill him
				sound.PlaySound("assets/sounds/DoomSounds/pain_02.ogg");
				deadEnemy->DeadState();
				SetScore(100);

				int tally = 0;

				for (int i = 0; i != m_enemies.size(); i++)
				{
					if (m_enemies[i]->IsEnemyDead())
					{
						tally ++;
					}
					// The win condition
					if (tally >= 3)
					{
						TheGame::Instance()->SetGameState(TheWinState::Instance());
					}
				}
			}
			else
			{
				// Hit a wall
				sound.PlaySound("assets/sounds/DoomSounds/impact_02.wav");
			}
		}
	}

	void Player::AddEnemy(Enemy* e)
	{
		m_enemies.push_back(e);
	}

	void Player::PlayerDamageTake()
	{
		SoundManager sound;

		sound.PlaySound("assets/sounds/DoomSounds/pain4.ogg");
		SetHealth(20);
	}

	void Player::SetHealth(int newHealth)
	{
		m_health = newHealth;
	}

	void Player::LoseHealth(int newHealth)
	{
		m_health -= newHealth;
	}

	int Player::GetHealth()
	{
		return m_health;
	}

	int Player::GetScore()
	{
		return m_score;
	}

	void Player::SetScore(int newScore)
	{
		m_score += newScore;
	}

	const Box3D &Engine::Player::GetPlayerBounds()
	{
		return m_playerBox;
	}

	const char* Player::GetTypeName() const
	{
		return("Player");
	}
}