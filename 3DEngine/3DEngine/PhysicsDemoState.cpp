#include "PhysicsDemoState.h"
#include "Game.h"
#include "MyGL.h"
#include "SoundManager.h"
#include "EventPoller.h"
#include "Particle.h"
#include "Spring.h"
#include "Constraint.h"
#include "Cloth.h"
#include "Vec3.h"
#include <AntTweakBar.h>

TwBar *bar;

float kval;
float minval;
float maxval;
float naturallength;
float invmass;
//const Vec3f setpos();

namespace Engine
{
	void PhysicsDemoState::OnActivated()
	{
		GameState::OnActivated();

		bar = TwNewBar("TweakBar");
		TwDefine(" GLOBAL help='AntTweakBar used for changing parameters.\n' ");

		//TwAddVarRW(bar, "InverseMass", TW_TYPE_FLOAT, 
		//	&invmass,
		//	" min=0 max=1000 group=Particle label='Inverse Mass' ");

		//TwAddVarRW(bar, "KValue", TW_TYPE_FLOAT, 
		//	&kval,
		//	" min=0 max=1000 group=Particle label='K Value' ");

		//TwAddVarRW(bar, "MinimumLength", TW_TYPE_FLOAT, 
		//	&minval,
		//	" min=0 max=1000 group=Particle label='Minimum Length' ");

		//TwAddVarRW(bar, "MaximumLength", TW_TYPE_FLOAT, 
		//	&maxval,
		//	" min=0 max=1000 group=Particle label='Maximum Length' ");

		//TwAddVarRW(bar, "NaturalLength", TW_TYPE_FLOAT, 
		//	&naturallength,
		//	" min=0 max=1000 group=Particle label='Natural Length' ");



		// Testing Spring and particles
		m_partImmovable.SetPos(Vec3f(0, 0, 0));
		m_partMovable.SetPos(Vec3f(0, -3, 0));
		m_partMovable.Movable();

		kval = 0.0001;
		minval = 2.8;
		maxval = 3.2;
		invmass = 10;

		m_partMovable.SetInvMass(invmass);


		m_spring.SetParticles(&m_partImmovable, &m_partMovable);


		// Previous version of setting up the cloth 
		//cloth.SetClothVals(0.6, 0.0, 2.0, 1.0);
		//cloth.CreateLattice(5, 5);

		// Initializing the lattice 
		//cloth.Initialize(0.001f, 0.9f, 1.2f, 1.0f, 3, 3, 100.0f);


		// Setting up GL lighting
		glShadeModel(GL_SMOOTH);
		glClearColor(0.2f, 0.2f, 0.4f, 0.5f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_COLOR_MATERIAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		GLfloat lightPos[4] = {-1.0,1.0,0.5,0.0};
		glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *) lightPos);

		glEnable(GL_LIGHT1);

		GLfloat lightAmbient1[4] = {0.0,0.0,0.0,0.0};
		GLfloat lightPos1[4] = {1.0,0.0,-0.2,0.0};
		GLfloat lightDiffuse1[4] = {0.5,0.5,0.3,0.0};

		glLightfv(GL_LIGHT1,GL_POSITION,(GLfloat *) lightPos1);
		glLightfv(GL_LIGHT1,GL_AMBIENT,(GLfloat *) lightAmbient1);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,(GLfloat *) lightDiffuse1);

		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	}

	void PhysicsDemoState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	PhysicsDemoState::PhysicsDemoState()
	{

	}

	void PhysicsDemoState::Draw()
	{
		// Setting up boolean flag for playing sound/music
		static bool play = false;

		if (!play)
		{
			play = true;
			//TheSoundManager::Instance()->PlayMusic("crab_nicholso.mp3");
		}

		// drawing
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0, 1.0, 0.5, 1000.0);


		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 3, 15, 0, 0, 0, 0, 1, 0);

		// Testing
		m_partImmovable.DrawGL();
		m_partMovable.DrawGL();
		m_spring.Draw();

		//m_cloth.DrawLattice();		// Creating Lattice
		TwDraw();		// Drawing AnTweakBar

		glTranslatef(-6.5,6,-9.0f); // centering the camera to the cloth object
		glRotatef(25,0,1,0); // rotate a bit to see the cloth from the side
	}

	void PhysicsDemoState::Update()
	{
		//m_partImmovable.Update();
		m_partMovable.Update();
		//m_partMovable.AddForce(Vec3f(1, 0, 0));
		m_spring.Update();

		//m_cloth.Update();
	}

	void PhysicsDemoState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			TwTerminate();
			SDL_Quit();
			exit(0);
		}

		if (k.keysym.sym == SDLK_w && k.state == SDL_PRESSED)
		{
			m_partMovable.AddForce(Vec3f(1, 0, 0));
		}
	}
}







// Early example of a setting up two particles and and assigning a spring to both
// These are left here for the purpose of referencing 
	// Setting up two particles, one with infinite mass
	// and one movable
	//immovable.SetInvMass(0);
	//immovable.SetPos(Vec3f(0, -4.0f, 0));

	//movable.SetInvMass(1.0f);
	//movable.SetPos(Vec3f(0, 1.0f, 0));
	
	// Assigning a spring to the 
	/*spring.SetParticles(&immovable, &movable);
	spring.SetNaturalLength(1.0f);
	spring.SetKVal(1.0f);*/


	//float ball_time = 0; // counter for used to calculate the z position of the ball

	////Cloth cloth1(14,10,55,45); // one Cloth object of the Cloth class
	//Vec3f ball_pos(7.0,-5.0,0.0); // the center of our one ball
	//float ball_radius = 2; // the radius of our one ball used for collision detection

		// Moving the Ball
		//ball_time++;
		//ball_pos.z = cos(ball_time / 50.0) * 7;


		//cloth1.drawShaded(); // finally draw the cloth with smooth shading

		//glPushMatrix(); // to draw the ball we use glutSolidSphere, and need to draw the sphere at the position of the ball
		//glTranslatef(ball_pos.x,ball_pos.y,ball_pos.z); // hence the translation of the sphere onto the ball position
		//glColor3f(0.4f,0.8f,0.5f);
		//glutSolidSphere(ball_radius-0.1,50,50); // draw the ball, but with a slightly lower radius, otherwise we could get ugly visual artifacts of cloth penetrating the ball slightly
		//glPopMatrix();


		//glDisable(GL_LIGHTING);


		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();


		// Simple state transition using keyboard input
		//if (k.keysym.sym == SDLK_SPACE &&  k.state == SDL_PRESSED)
		//{
		//	TheGame::Instance()->SetGameState(ThePlayState::Instance());
		//	TheGame::Instance()->Run();
		//}

		//glDisable(GL_LIGHTING);
		//glBegin(GL_POLYGON);
		////glColor3f(0.8f ,0.8f ,1.0f);
		////glVertex3f(-200.0f,-100.0f,-100.0f);
		////glVertex3f(200.0f,-100.0f,-100.0f);
		////glColor3f(0.4f,0.4f,0.8f);	
		////glVertex3f(200.0f,100.0f,-100.0f);
		////glVertex3f(-200.0f,100.0f,-100.0f);
		//glEnd();
		//glEnable(GL_LIGHTING);