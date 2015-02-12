#include "PlayState.h"
#include "Game.h"
#include "MyGL.h"
#include "SoundManager.h"
#include "Car.h"
#include "FontManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include "Billboard.h"
#include "Light.h"
#include "Material.h"
#include "Timer.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "Player.h"
#include "CollisionMesh.h"
#include "Enemy.h"
#include "Room.h"
#include "WinState.h"
#include "LossState.h"


// A set of global variables that were previously used
//ObjMesh mesh;
//Player player;
//CollisionMesh coll;
//Enemy enemy;

namespace Engine
{
	void PlayState::OnActivated()
	{
		GameState::OnActivated();
		
		text.Load("Assets/fonts/Doom32Bit.png", 16, 16);
		texture.Load("Assets/Images/textures/hud.png");

		//enemy.Load();
	
		//player.SetCollisionMesh(&coll);
		// Player should be first as we set up the camera in his Draw() function
		Player* player = new Player;
		Room* room = new Room;
		room->Load(0);

		// Setting player health
		player->SetHealth(100);

		player->SetCollisionMesh(room->GetCollMesh());
		TheGame::Instance()->AddGameObject(player);
		TheGame::Instance()->AddGameObject(room);

		// Could loop here for lots of enemies
		for (int i = 0; i < 10; i++)
		{
			Enemy* enemy = new Enemy;
			enemy->Load();
			enemy->SetCollisionMesh(room->GetCollMesh());
			TheGame::Instance()->AddGameObject(enemy);
			enemy->SetPlayer(player);
			player->AddEnemy(enemy);
		}
	}


	void PlayState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	PlayState::PlayState()
	{
		GLuint texId = -1;
	}

	void Engine::PlayState::Draw()
	{
		Player player;

		static bool play = false;

		//if (!play)
		//{
		//	play = true;
		//	TheSoundManager::Instance()->PlayMusic("assets/music/DoomMusic/e1m1.midi");
		//}

		//ObjMesh object;

		//object.Load("main.cpp");

		//glClearColor(1, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_BLEND);
		glEnable(GL_CULL_FACE);

		//glViewport(/*i * *//*333*/0,/*i * *//*333*/0, 666, 666/* 333, 333*/);
		
	
			static float b = 0;
			b += 0.01f;
		
			Light lig;
			Material mat;

			float lightposX = sin(b) * 10.0;
			float lightposY = 10.0;
			float lightposZ = cos(b) * 10.0;


			lig.SetLightDirection(lightposX, lightposY, lightposZ);
			lig.SetAmbient(0.2,0.2,0.2,1);
			lig.SetDiffuse(0.5, 0.5, 0.5, 1);
			lig.SetSpecular(1,1,1,1);

		
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glCullFace(GL_BACK);


			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(91.0, 1.0, 0.5, 1000.0);

			// Initializing player viewport
			player.PlayerViewpoint();


			// re-enabling lighting
			glEnable(GL_LIGHTING);


			static float a = 0;
			a += 0.5f;


			TheGame::Instance()->DrawGameObjects();

			glDisable(GL_DEPTH_TEST);
			glDisable(GL_LIGHTING);
			//glDepthMask(GL_FALSE);
		

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

		
			glEnable(GL_TEXTURE_2D);
			texture.Draw();

			Billboard bill;

			bill.Draw(Vec3f (0, 0, 0), 1.0f);

			//glTranslatef(0, 0, 0);

		
			player.SetHealth(100);

			int score;
			int health;

			health = player.GetHealth();
			score = player.GetScore();

			char scoreBuff[32];

			sprintf_s(scoreBuff, "Score: %d", score);

			std::string scoreStr(scoreBuff);
	
			text.Draw(scoreStr, -1.0, 0.8, 0.06f);
		
		
			char healthBuff[32];

			sprintf_s(healthBuff, "Health: %d", health);

			std::string healthStr(healthBuff);

			text.Draw(healthStr, -1.0, 0.9, 0.06f);
		
			glEnable(GL_TEXTURE_2D);

			//text.Draw("Doom Prototype", -1.0, 0.9, 0.06f);
	
		//}
	}

	void Engine::PlayState::Update()
	{
		TheGame::Instance()->UpdateGameObjects();
	}

	void Engine::PlayState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			SDL_Quit();
			exit(0);
		}
	}

}