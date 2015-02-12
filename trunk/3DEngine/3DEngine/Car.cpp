#include "Car.h"
#include "MyGL.h"
#include "Timer.h"

Engine::Car::Car()
{
	m_vel = 0;
	m_acc = 0;
	m_pos = 0;
	m_turn = 0;
	m_wheelTurn = 90.0f;
}

void Engine::Car::Draw()
{
	glPushMatrix();
	glTranslatef(0, 0, m_pos);

	// bicycle
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 1.0f);
	glutSolidCube(1.0f);

	// bicycle front
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, -1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0.2, 0.3);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Handle 1
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.5, 0.5, 0.4);
	glutSolidCube(0.2f);
	glPopMatrix();

	//Handle 2
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-0.5, 0.5, 0.4);
	glutSolidCube(0.2f);
	glPopMatrix();

	// third body part
	glPushMatrix();
	glColor3f(0.5, 1, 1);
	glTranslatef(0, -0.2, 1);
	glRotatef(45.0, 0, 1, 0);
	glutSolidCube(1.0f);
	glPopMatrix();

	// back wheel
	glPushMatrix();
	glTranslatef(0.0f, -0.5, -1.5);
	glRotatef(90.0, 0, 1, 0);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidTorus(0.1f, 0.7f, 15, 20);
	glPopMatrix();

	// front wheel
	glPushMatrix();
	glTranslatef(0.0f, -0.5, 1.5);
	glRotatef(m_wheelTurn, 0, 1, 0);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidTorus(0.1, 0.7f, 15, 20);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void Engine::Car::Update()
{
	m_vel;
	m_acc;

	m_acc += m_vel;

	//m_pos = m_vel / Timer::GetDt();


	m_turn;
	m_wheelTurn;
}


void Engine::Car::HandleEvent(const SDL_Event &k)
{
	if (k.type == SDL_KEYDOWN)
	{
		if ((k.key.keysym.sym == SDLK_w 
			|| k.key.keysym.sym == SDLK_a)
			&&  k.type == SDL_PRESSED)
		{
			m_acc += 10.0f;
			m_wheelTurn += 45;
		}

		//if ((k.key.keysym.sym == SDLK_w 
		//	&& k.key.keysym.sym == SDLK_d)
		//	&&  k.type == SDL_PRESSED)
		//{
		//	m_acc += 10.0f;
		//	m_wheelTurn -= 45;
		//}

		//if (k.key.keysym.sym == SDLK_w 
		//	&&  k.type == SDL_PRESSED)
		//{
		//	m_acc += 10.0f;
		//}

		//if (k.key.keysym.sym == SDLK_s
		//	&&  k.type == SDL_PRESSED)
		//{
		//	m_acc -= 10.0f;
		//	//m_wheelTurn -= 45;
		//}
	}
}