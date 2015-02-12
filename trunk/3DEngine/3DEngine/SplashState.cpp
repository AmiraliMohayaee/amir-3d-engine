#include "SplashState.h"
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


namespace Engine
{
	SplashState::SplashState()
	{
		GLuint texId = -1;
	}

	void SplashState::OnActivated()
	{
		GameState::OnActivated();

		text.Load("Assets/fonts/Doom32Bit.png", 16, 16);
		texture.Load("Assets/Images/textures/hud.png");
		texture.Load("assets/images/textures/doom1.png");
	}

	void SplashState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	void SplashState::Draw()
	{
		static bool play = false;

		if (!play)
		{
			play = true;
			//TheSoundManager::Instance()->PlayMusic("DoomMusic/d1title.mid");

			TheSoundManager::Instance()->PlayMusic("assets/DoomMusic/d1title2.mid");
		}

		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glCullFace(GL_BACK);

		glEnable(GL_TEXTURE_2D);

		texture.Draw();
		Billboard bill;

		bill.Draw(Vec3f (0, 0, 0), 1.0f);

		//glTranslatef(0, 0, 0);


		glEnable(GL_TEXTURE_2D);

		// Text.Draw ("string", x-axis, y-axis, size)
		text.Draw("Doom Prototype", -0.6, 0.9, 0.08f);

		text.Draw("To begin the onslaught, ", -0.5, 0.7, 0.06f);
		text.Draw("press the Space key.", -0.4, 0.65, 0.06f);

		text.Draw("To exit the game, press Escape.", -1.0, 0.60, 0.06f);
		//text.Draw()
	}

	void SplashState::Update()
	{

	}

	void SplashState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_SPACE &&  k.state == SDL_PRESSED)
		{
			TheGame::Instance()->SetGameState(ThePlayState::Instance());
		}

		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			//TheGame::Instance()->SetGameState(ThePlayState::Instance());

			SDL_Quit();
			exit(0);
		}


		//if (k.keysym.sym == SDLK_SPACE &&  k.state == SDL_PRESSED)
		//{
		//	TheSoundManager::Instance()->PlayMusic("E4E.mp3");
		//}
	}

}