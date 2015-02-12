#ifndef PLAYER_H
#define PLAYER_H

#include "RidgidBodyGO.h"
#include "EventHandler.h"
#include "MyGL.h"
#include "Billboard.h"
#include "TextureManager.h"
#include "CollisionMesh.h"
#include "Mgc/MgcDistLin3Tri3.h"
#include <vector>
#include "Box3D.h"


namespace Engine
{
	class Enemy;

	class Player : public RidgidBodyGO, public EventHandler
	{
	public:
		Player();
		~Player();
		//virtual void Load();
		virtual void Draw() override;
		virtual void Update() override;
		void PlayerViewpoint();

		// Health related
		void PlayerDamageTake();
		void SetHealth(int newHealth);
		int GetHealth();
		void LoseHealth(int newHealth);

		// Cheap bounding boxes
		const Box3D &GetPlayerBounds();

		// Score Related
		int GetScore();
		void SetScore(int newScore);

		// over-riding Keyboard and Motion and key events
		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);
		virtual void OnMouseMotionEvent(const SDL_MouseMotionEvent&);
		virtual void OnMouseButtonEvent(const SDL_MouseButtonEvent&);

		void CheckFire(const Tri& tri, const LineSeg3& line);
		void AddEnemy(Enemy*);

		virtual const char* GetTypeName() const;

	protected:
		int m_health;
		int m_armor;
		int m_keys;
		int m_arms;
		int m_score;

		// Used for measuring the determine whether player
		// is in range to shoot enemy
		int m_attackRange;

	private:
		Billboard m_billboard;
		TextureManager m_texture;

		// Camera Position
		GLdouble m_eyex;
		GLdouble m_eyey;
		GLdouble m_eyez;

		// Coords of where we're looking at
		GLdouble m_centerx;
		GLdouble m_centery;
		GLdouble m_centerz;

		// camera rotation
		GLdouble m_upx;
		GLdouble m_upy;
		GLdouble m_upz;

		int m_newPos;

		float m_heading;
		bool m_wasd[4];

		Box3D m_playerBox;

		std::vector <Enemy*> m_enemies;
	};

	//typedef std::vector<m_keys> Keys;
	//typedef Singleton<Player> ThePlayer;
}

#endif