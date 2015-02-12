#include "FuzzyLogicTestState.h"
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


#include "ffllapi/FFLLAPI.h"	// FFLL API
#include <iostream>	// for i/o functions

#define OUR_HEALTH	0 // our health is 1st variable
#define ENEMY_HEALTH	1 // enemy health is 2nd variable

// Use for testing the fuzzy logic

namespace Engine
{
	FuzzyLogicTestState::FuzzyLogicTestState()
	{

	}

	void FuzzyLogicTestState::Draw()
	{
		
	}

	void FuzzyLogicTestState::Update()
	{
		
	}

	void FuzzyLogicTestState::OnActivated()
	{
		GameState::OnActivated();
	}

	void FuzzyLogicTestState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	void FuzzyLogicTestState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			SDL_Quit();
			exit(0);
		}
	}

}