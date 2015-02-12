#include "Game.h"
#include "Screen.h"
#include "GameState.h"
#include "EventPoller.h"
#include "GameObject.h"
#include <assert.h>
#include "Timer.h"


namespace Engine
{
	Game::Game()
	{
		m_state = 0;
		m_pCollisionSystem = 0;
	}

	void Game::SetCollisionSystem(CollisionSystem* pCs)
	{
		m_pCollisionSystem = pCs;
	}

	void Game::UpdateCollision()
	{
		assert(m_pCollisionSystem);

		m_pCollisionSystem->
			Update(&m_gameObjects);
	}

	void Game::HandleCollision(GameObject*  g1, GameObject* g2)
	{
		TypePair tp(
			g1->GetTypeName(), g2->GetTypeName());

		CollisionMap::iterator it =
			m_collMap.find(tp);

		if (it != m_collMap.end())
		{
			CollisionHandler ch = it->second;
			ch(g1, g2);
		}

		//Doing the same thing again, but with the two types reversed
		std::swap(tp.first, tp.second);

		it = m_collMap.find(tp);

		if (it != m_collMap.end())
		{
			CollisionHandler ch = it->second;
			ch(g2, g1);
		}
	}


	bool Game::AddCollisionHandler(
		const std::string& typeName1,
		const std::string& typeName2,
		CollisionHandler ch)
	{
		TypePair tp(typeName1, typeName2);
		m_collMap[tp] = ch;
		return true;
	}


	void Game::Run()
	{
		while(true)
		{
			Draw();
			Update();
			TheScreen::Instance() -> Flip();
		}
	}


	void Game::Draw()
	{
		m_state->Draw();
	}

	void Game::Update()
	{
		Timer::Instance() -> Update();

		TheEventPoller::Instance() -> Update();

		m_state->Update();

		//UpdateCollision();
	}

	void Game::SetGameState(GameState* gs)
	{
		if(m_state)
		{
			m_state->OnDeActivated();
			TheEventPoller::Instance()->RemoveHandler(m_state);
		}

		m_state = gs;

		m_state->OnActivated();
		TheEventPoller::Instance()->AddHandler(m_state);
	}

	void Game::AddGameObject(GameObject* go)
	{
		m_gameObjects[go->GetId()] = go;	
	}

	void Game::DrawGameObjects()
	{
		for(GameObjects::iterator it = m_gameObjects.begin();
			it != m_gameObjects.end();
			++it)
		{
			it->second->Draw();
			//(*it).second->Draw; //Another way to call the second
		}
	}

	void Game::RemoveGameObjects(GameObject* go)
	{
		for(GameObjects::iterator it = m_gameObjects.begin();
		it != m_gameObjects.end();
		++it)
		{
		delete &it->second;
		//it->second->Update();
		//(*it).second->Draw; //Alternative way of the above method
		}
	}

	void Game::UpdateGameObjects()
	{
		for(GameObjects::iterator it = m_gameObjects.begin();
			it != m_gameObjects.end();
			++it)
		{
			it->second->Update();
			//(*it).second->Draw; //Alternative way of the above method
		}
	}
}