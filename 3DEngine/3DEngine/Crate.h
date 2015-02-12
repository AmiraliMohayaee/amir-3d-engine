#pragma once 

#include "GameObject.h"
#include "ObjMesh.h"
#include "CollisionMesh.h"


namespace Engine
{
	class Crate
	{
	private:
		ObjMesh mesh;
		CollisionMesh coll;

	public:
		Crate();
		virtual void Draw();
		virtual void Update();
		virtual bool Load(File*);

		virtual const char* GetTypeName() const;

		CollisionMesh* GetCollMesh() { return &coll; }
	};
}