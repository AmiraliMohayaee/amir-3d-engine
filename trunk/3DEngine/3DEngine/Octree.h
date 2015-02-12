#pragma once

#include <vector>
#include "Box3D.h"
#include "Tri.h"
#include "Capsule.h"
#include "Vertex.h"


namespace Engine
{
	class Octree
	{
	public:
		virtual ~Octree() {}
		virtual void Draw() = 0;

	protected:
		// Every concrete Octree type needs a bounding box
		Box3D m_box;
	};

	class OctreeLeaf : public Octree
	{
	public:
		OctreeLeaf(const Tris& tris, const Box3D& box);

		virtual void Draw();

	private:
		Tris m_tris;
	};

	class OctreeComposite : public Octree
	{
	public:
		OctreeComposite(const Box3D& box);

		virtual void Draw();
		void AddChild(Octree*);

	private:
		std::vector<Octree*> m_children;
	};
}