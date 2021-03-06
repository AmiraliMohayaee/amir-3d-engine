#include "LossState.h"
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

	void LossState::OnActivated()
	{
		GameState::OnActivated();

		text.Load("assets/fonts/Doom32Bit.png", 16, 16);
		texture.Load("assets/images/textures/Final.png");
	}

	void LossState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	LossState::LossState()
	{
		GLuint texId = -1;
	}

	void LossState::Draw()
	{
		static bool play = false;

		if (!play)
		{
			play = true;
			TheSoundManager::Instance()->PlayMusic("E4E.mp3");
		}

		glEnable(GL_TEXTURE_2D);
		texture.Draw();

		Billboard bill;

		bill.Draw(Vec3f (0, 0, 0), 1.0f);

		//glTranslatef(0, 0, 0);

		glEnable(GL_TEXTURE_2D);
		text.Draw("Game Over!", -1.0, 0.8, 0.08f);

		text.Draw("You were killed by the demons!", -1.0, 0.7, 0.06f);
		text.Draw("Press Escape to exit", -1.0, 0.6, 0.06f);
	}

	void LossState::Update()
	{
		//TheGame::Instance()->UpdateGameObjects();
		m_elapsedTime += 
			Timer::Instance()->GetDt();
		if (m_elapsedTime > 10.0f)
		{
			// Go to next state
			//TheGame::Instance()->SetGameState(TheTexturingState::Instance());
		}
	}

	void LossState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			SDL_Quit();
			exit(0);
		}
	}

}