#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "GameObject.h"
#include "CollisionSystem.h"
#include <string>
#include <map>

namespace Engine
{
	class GameState;

	class Game : public NonCopyable
	{
	private:
		Game();
		friend Singleton<Game>; 

	public:
		void Run();
		void Draw();
		void Update();
		void SetGameState(GameState* gs);

		void DrawGameObjects();
		void UpdateGameObjects();
		void RemoveGameObjects(GameObject* go);
		void AddGameObject(GameObject* go);

		void SetCollisionSystem(CollisionSystem*);
		void UpdateCollision();

		typedef void (*CollisionHandler)
			(GameObject*, GameObject*);

		void HandleCollision(GameObject*  g1, GameObject* g2);

		bool AddCollisionHandler(
			const std::string& typeName1,
			const std::string& typeName2,
			CollisionHandler ch);

	private:
		GameState* m_state;

		GameObjects m_gameObjects;
		CollisionSystem* m_pCollisionSystem;

		typedef std::pair<std::string, std::string> 
			TypePair;

		typedef std::map<TypePair, CollisionHandler>
			CollisionMap;
		CollisionMap m_collMap;
	};

	typedef Singleton<Game> TheGame;
}

#endif