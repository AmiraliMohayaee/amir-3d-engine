#include "CollisionMesh.h"
#include "Mgc/MgcDistLin3Tri3.h"
#include <windows.h>
#include <GL/gl.h>
#include "ObjMeshFunction.h"


namespace Engine
{
	void CollisionMesh::AddTri(const Tri& t)
	{
		m_tris.push_back(t);
	}

	void CollisionMesh::Draw()
	{
		for (unsigned int i = 0; i < m_tris.size(); i++)
		{
			//const Tri& tri = m_tris[i];
			//glNormal3f(tri.m_normal.x, tri.m_normal.y, tri.m_normal.z);
			//// Below is used for drawing lines around boxes to show triangles
			////glBegin(GL_LINE_LOOP);
			//for (int j = 0; j < 3; j++)
			//{
			//	glVertex3f(tri.m_verts[j].x, tri.m_verts[j].y, tri.m_verts[j].z);
			//}
			////glEnd();

			m_tris[i].Draw();
		}
	}

	// Calculate the distance from the triangle to the line seg.
	// This is complicated so we use the Mgc library.
	static float SqDist(const Engine::Tri& tri, const Engine::LineSeg3& line)
	{
		MgcSegment3 mgcSeg;
		mgcSeg.Origin() = MgcVector3(line.GetStart().x, line.GetStart().y, line.GetStart().z);
		Engine::Vec3f dir = line.GetEnd() - line.GetStart();
		mgcSeg.Direction() = MgcVector3(dir.x, dir.y, dir.z);

		MgcTriangle3 mgcTri;
		mgcTri.Origin() = MgcVector3(tri.verts[0].m_point.x, tri.verts[0].m_point.y, tri.verts[0].m_point.z);
		Engine::Vec3f edge0 = tri.verts[1].m_point - tri.verts[0].m_point;
		Engine::Vec3f edge1 = tri.verts[2].m_point - tri.verts[0].m_point;
		mgcTri.Edge0() = MgcVector3(edge0.x, edge0.y, edge0.z);
		mgcTri.Edge1() = MgcVector3(edge1.x, edge1.y, edge1.z);

		return MgcSqrDistance(mgcSeg, mgcTri);
	}

	bool CollisionMesh::Intersects(const Capsule& c, TriPtrs* pVec)
	{
		float rsq = c.GetRadius() * c.GetRadius();

		for (unsigned int i = 0; i < m_tris.size(); i++)
		{
			float dsq = SqDist(m_tris[i], c.GetLineSeg());

			if(dsq <  rsq)
			{
				pVec->push_back(&m_tris[i]);
			}
		}

		return !pVec->empty();
	}

	void CollisionMesh::objLoad(const ObjMesh& m)
	{
		for(Groups::const_iterator it = m.m_groups.begin();
			it != m.m_groups.end();
			++it)
		{
			// Draw this group
			const Group& g = it->second;

			for (unsigned int j = 0; j < g.m_faces.size(); j++)
			{

				const Face& f = g.m_faces[j];

				Tri tri;
				// for each vertex
				for (int i = 0; i < 3; i++)
				{
					int id = f.m_pointIndex[i];
					Vec3f coord = g.m_mesh->m_coords[id];
					tri.verts[i] = coord;
				}
				AddTri(tri);
			}
		}
	}
}