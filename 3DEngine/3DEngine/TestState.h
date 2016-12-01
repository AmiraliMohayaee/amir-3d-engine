////////////////////////////////////////////////////////////////
////	Welcome to the shooting range!
////	Author: Amirali Mohayaee
////	State used for testing all the horrible things that 
////	don't work and need fixing.
////	Last update: 21/05/2015
////////////////////////////////////////////////////////////////

#pragma once

#include "Game.h"
#include "GameState.h"
#include "Singleton.h"
#include "MyGL.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "Crate.h"
#include "CollisionSphere.h"
#include "CollisionMesh.h"
#include "GLShader.h"
#include "Octree.h"
#include "CameraController.h"
#include "OBB3.h"
#include "MakeOctree.h"
#include "Box3D.h"
#include "File.h"
#include "Trigger.h"
//#include "TLSoundCue.h"


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
		OBB3 m_obb;
		//CameraController m_fpsCamera;
		File m_textFile;
		//TLSoundCue m_tlkCue;
		//Trigger<int, int> m_trigger;
	};

	typedef Singleton<TestState> TheTestState;
}