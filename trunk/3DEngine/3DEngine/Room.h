#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include "ObjMesh.h"
#include "CollisionMesh.h"

namespace Engine
{
	class Room : public GameObject
	{
	public:
		Room();
		virtual void Draw();
		virtual void Update();
		virtual bool Load(File*);

		virtual const char* GetTypeName() const;

		CollisionMesh* GetCollMesh() { return &coll; }

	private:
		ObjMesh mesh;
		CollisionMesh coll;
	};
}

#endif