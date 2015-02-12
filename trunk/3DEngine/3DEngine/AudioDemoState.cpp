#include "AudioDemoState.h"

#include "Game.h"
#include "MyGL.h"
#include "FontManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include "Billboard.h"
#include "Timer.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "PortSndAudioManager.h"
#include <cmath>


namespace Engine
{

void AudioDemoState::OnActivated()
{
	GameState::OnActivated();

	PortSndAudioManager* audioMngr = TheAudioManager::Instance();
	audioMngr->PAInitialize();
	if (!m_soundFile.Load("Assets/music/DoomMusic/doom.wav"))
	{
		std::cout << "File not loaded...\n";
		system("pause");
		exit(0);
	}

	//text.Load("assets/images/textures/Doom32Bit.png", 16, 16);
	//texture.Load("assets/images/textures/Final.png");
}

void AudioDemoState::OnDeActivated()
{
	GameState::OnDeActivated();
}

AudioDemoState::AudioDemoState()
{
	GLuint texId = -1;
}


void AudioDemoState::Draw()
{
	static float camrot = 0;
	camrot += 0.2;

	static bool pers = false;
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(91.0, 1.0, 0.5, 1000.0);
	
	gluLookAt(0, 0, 5.0, 0, 0, 0, 0, 1.0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	

    static float a = 0;
    a += 1.5f;
	static float b = 0;
	b += 2.0f;


	// This was meant to showcase the panning functionalities which were later not implemented
	// due to lack of time. These essentially end up being not-so-pretty eye candy for a demo
	// which only has one global sound source 
	// Teapot
	glPushMatrix();

		glRotatef(a, 0.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0, 0);
		glutSolidTeapot(1.0f);

		// Com'panning Cube
		glPushMatrix();
			glTranslatef(1.0f, 0.0f, 0.0f);
			glRotatef(b, 0.0f, 1.0f, 0.0f);
			glColor4f(1.0f, 1.0f, 0.0, 0.5f);
			glutSolidCube(1.0f);
		glPopMatrix();
	
	glPopMatrix();

    //glutSwapBuffers();
    //glutPostRedisplay();
}

void AudioDemoState::Update()
{
	static bool play = false;

	if (!play)
	{
		play = true;
		m_soundFile.StartStream();
	}
}

void AudioDemoState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
{
	if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
	{
		SDL_Quit();
		exit(0);
	}
}

}