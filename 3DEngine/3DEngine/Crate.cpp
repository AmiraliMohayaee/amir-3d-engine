#include "Crate.h"

namespace Engine
{
	Crate::Crate()
	{

	}

	void Crate::Draw()
	{
		mesh.Draw();
		//glLineWidth(3);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		coll.Draw();
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
	}


	void Crate::Update()
	{

	}


	bool Crate::Load(File*)
	{
		// Loading in the level and testing collision
		mesh.Load("assets/levels/Room.obj");
		coll.objLoad(mesh);

		// Loading in skybox, this time not testing 
		// for collisions
		//mesh.Load("SkyBox.obj");

		return true;
	}

	const char* Crate::GetTypeName() const
	{
		return ("Crate");
	}
}