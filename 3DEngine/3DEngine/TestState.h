////////////////////////////////////////////////////////////////
////	Welcome to the shooting range!
////	Author: Amirali Mohayaee
////	State used for testing all the horrible things that 
////	don't work and need fixing.
////	Last update: 16/01/2015
////////////////////////////////////////////////////////////////

#pragma once

#include "GameState.h"
#include "Singleton.h"
#include "MyGL.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "Crate.h"
#include "CollisionSphere.h"
#include "GLShader.h"
#include "Octree.h"
#include "TimeLine.h"
#include "CameraController.h"
#include "OBB3.h"


namespace Engine
{
	class TestState : public GameState, public NonCopyable
	{
	public:
		TestState();
		virtual void Draw();
		virtual void Update();
		virtual void OnActivated() override;
		virtual void OnDeActivated() override;
		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

	private:		
		FontManager text;
		TextureManager texture;
		GLuint texId;
		ObjMesh m_mesh;
		Crate m_crate;
		CollisionSphere cs1;
		CollisionSphere cs2;
		GLShader m_shader;
		Octree* m_oct;
		Tris m_tris;
		TimeLine tl;
		OBB3 m_obb;
		CameraController m_fpsCamera;
	};

	typedef Singleton<TestState> TheTestState;
}