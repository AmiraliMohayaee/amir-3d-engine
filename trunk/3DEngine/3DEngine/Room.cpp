#include "Room.h"


namespace Engine
{
	Room::Room()
	{

	}

	void Room::Draw()
	{
		mesh.Draw();
		//glLineWidth(3);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		coll.Draw();
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
	}


	void Room::Update()
	{

	}


	bool Room::Load(File*)
	{
		// Loading in the level and testing collision
		mesh.Load("assets/levels/Room.obj");
		coll.objLoad(mesh);

		// Loading in skybox, this time not testing 
		// for collisions
		//mesh.Load("SkyBox.obj");

		return true;
	}


	const char* Room::GetTypeName() const
	{
		return ("Room");
	}
}