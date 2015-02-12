#ifndef COLLISION_MESH_H
#define COLLISION_MESH_H

#include <vector>
#include "Vec3.h"
#include "Capsule.h"
#include "Tri.h"
#include "ObjMesh.h"

namespace Engine
{
	class CollisionMesh
	{
	public:
		void AddTri(const Tri& t);
		void Draw(); // for debugging

		void objLoad(const ObjMesh&);

		typedef std::vector<const Tri*> TriPtrs;

		// Returns true if the given capsule intersects this mesh.
		// If there is an intersection, the vector is populated:
		// each element is a pointer to a Triangle which intersects 
		// the capsule.
		bool Intersects(const Capsule& c, TriPtrs* pVec);

	private:
		Tris m_tris;
	};
}

#endif