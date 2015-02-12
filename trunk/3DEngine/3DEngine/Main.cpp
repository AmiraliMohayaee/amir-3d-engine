// Animation library definitions for Debug and Release mode
//#ifdef _DEBUG
//#pragma comment (lib, "../../Animation/Debug/AnimLib.lib")
//#else
//#pragma comment (lib, "../../Animation/Release/AnimLib.lib")
//#endif

#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <string>
#include "Timer.h"
#include "Screen.h"
#include "Report.h"
#include "Joystick.h"
#include "Game.h"
#include "PlayState.h"
#include "SplashState.h"
#include "PhysicsDemoState.h"
#include "AIDemoState.h"
#include "AudioDemoState.h"
#include "TestState.h"
#include "File.h"
#include "MyGL.h"
#include <AntTweakBar.h>


#undef main

// 1.1/1.2 GL Shader initialization
//#include "GLShader.h"
//
//Engine::GLShader glShader;
//
//PFNGLPOINTPARAMETERFVPROC
//	glPointParameterfv = 0;


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//Engine::EnableJoysticks();

	int height = 600;
	int width = 800;

	if (!Engine::TheScreen::Instance()->Init(width, height, false))
	{
		Engine::ReportError("Error occurred. Could not open window.");
		return 0;
	}

	// glut initialized first before glew
	glutInit( &argc, argv );
	//glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 

	//glewInit();

	 GLenum GlewINIT = glewInit();
	 if (GlewINIT != GLEW_OK)
	 {
		 std::cout << "Glew failed to Initialize. Error: " << glewGetErrorString(GlewINIT) << std::endl;
		 exit(0);
	 }

	// Initialize AntTweakBar
    TwInit(TW_OPENGL, NULL);

	// Tell the window size to AntTweakBar
    TwWindowSize(width, height);

	//Setting Windows caption
	SDL_WM_SetCaption("Demo", NULL);

	Engine::Timer::Instance();

	// Initial state transition
	Engine::TheGame::Instance()->SetGameState(Engine::ThePhysicsDemoState::Instance());
	Engine::TheGame::Instance()->Run();
	
	return 0;
}