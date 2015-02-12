#include "TestState.h"
#include "Game.h"
#include "MyGL.h"
#include "SoundManager.h"
#include "FontManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include <cmath>
#include "Billboard.h"
#include "Light.h"
#include "Material.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "Player.h"
#include "CollisionMesh.h"
#include "DebugDraw.h"
#include "Matrix.h"
#include "TimeLine.h"
#include "CollisionSphere.h"
#include "MakeOctree.h"
#include "Box3D.h"
#include "Picking.h"
#include "OBB3.h"



namespace Engine
{
	void TestState::OnActivated()
	{
		GameState::OnActivated();

		//CameraController* cc = new CameraController;
		TheGame::Instance()->AddGameObject(&m_fpsCamera);
		m_fpsCamera.SetPos(Vec3f(0, 0, 0));


		//cs1.SetRadius(1.0f);
		//cs1.SetPos(Vec3f(0, 0, 0));

		//cs2.SetRadius(1.3f);
		//cs2.SetPos(Vec3f(3, 0, 0));

		//Crate* crate = new Crate;
		//crate->Load(0);
		//m_mesh.Load("crate2/crate2.obj");

		//Tri tri1;
		//tri1.verts[0].m_point = Vec3f(0, 0, 0);
		//tri1.verts[1].m_point = Vec3f(0, 1, 0);
		//tri1.verts[2].m_point = Vec3f(1, 1, 0);

		//Tri tri2;
		//tri2.verts[0].m_point = Vec3f(1, 2, 0);
		//tri2.verts[1].m_point = Vec3f(0, 2, 0);
		//tri2.verts[2].m_point = Vec3f(2, 3, 0);

		//Tri tri3;
		//tri3.verts[0].m_point = Vec3f(4, 4, 1);
		//tri3.verts[1].m_point = Vec3f(3, 4, 1);
		//tri3.verts[2].m_point = Vec3f(3, 6, 1);

		//Tri tri4;
		//tri4.verts[0].m_point = Vec3f(8, 3, 7);
		//tri4.verts[1].m_point = Vec3f(5, 3, 6);
		//tri4.verts[2].m_point = Vec3f(8, 8, 5);

		//Tri tri5;
		//tri5.verts[0].m_point = Vec3f(2, 0.5f, 0);
		//tri5.verts[1].m_point = Vec3f(1.5f, 0.5f, 0);
		//tri5.verts[2].m_point = Vec3f(2, 1, 0.5f);

		//m_tris.push_back(tri1);
		//m_tris.push_back(tri2);
		//m_tris.push_back(tri3);
		//m_tris.push_back(tri4);
		//m_tris.push_back(tri5);

		//Box3D worldBox1(Vec3f(0, 0, 0), Vec3f(8, 8, 8));

		//m_oct = MakeOctree(m_tris, worldBox1, 0);

		//GLShader shader;
		//m_shader.Load("Vertex Shader.vs", "Frag Shader.fs");

		//text.Load("Assets/fonts/Doom32Bit.png", 16, 16);
	}

	void TestState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}

	TestState::TestState()
	{
		GLuint texId = -1;
	}

	void TestState::Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glEnable(GL_LIGHT0);
		//glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		//glEnable(GL_BLEND);
		//glEnable(GL_CULL_FACE);


		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glCullFace(GL_BACK);


		static float b = 0;
		b += 0.01f;


		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//gluPerspective(60.0, 1.0, 0.5, 1000.0);

		// Setting up custom camera controller
		m_fpsCamera.Draw();


		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();
		//gluLookAt(cos(b) * 20, 7, sin(b) * 20, 
		//	0, 3, 0,
		//	0, 1, 0);

		//m_shader.UseThisShader();

		//Box3D mainTestBox(Vec3f(0, 0, 0), Vec3f(10, 10, 10));
		//mainTestBox.Draw();

		//Box3D childTestBox = mainTestBox.MakeOctreeChild(7);
		//childTestBox.Draw();

		//m_oct->Draw();
		
		// Oriented Bounding Box test
		//OBB3 obb(Vec3f(1, 1, 1), Vec3f(10, 10, 10));
		//obb.Draw();

		//OBB3 obb1(Vec3f(0, 0, 0), Vec3f(5, 5, 5));
		//obb1.Draw();


		//glDisable(GL_DEPTH_TEST);
		//glDisable(GL_LIGHTING);
		//glDisable(GL_COLOR_MATERIAL);
		//glDepthMask(GL_FALSE);

		glPushMatrix();
				DebugDraw dd;
				dd.DrawCoordID();
		glPopMatrix();


			//static float t = 0;
			//t += 0.01f;
			//m_shader.Set("t", t);
			
			//glPushMatrix();
			//glRotatef(45, 1, 0, 0);
			//glutSolidTeapot(2.0f);
			//glPopMatrix();

			//m_mesh.Draw();


			//cs1.Draw();
			//cs2.Draw();


		
		//glEnable(GL_TEXTURE_2D);
		//texture.Draw();

		//glEnable(GL_LIGHTING);


		//Billboard bill;

		//bill.Draw(Vec3f (0, 0, 0), 1.0f);

		//glEnable(GL_TEXTURE_2D);

		TheGame::Instance()->DrawGameObjects();
	}

	void TestState::Update()
	{
		m_fpsCamera.Update();	// Update camera controller

		//cs1.Update(cs2);
		//cs1.Update(cs1);

		//tl.Update();

		TheGame::Instance()->UpdateGameObjects();
	}

	void TestState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		//if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		//{
		//	SDL_Quit();
		//	exit(0);
		//}
	}
}