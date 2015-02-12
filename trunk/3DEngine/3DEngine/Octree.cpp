#include "Octree.h"
#include "MyGL.h"


namespace Engine
{
	// Set to false to draw all octants; true to draw leaves only
	static bool s_drawLeavesOnly = false;

	OctreeComposite::OctreeComposite(const Box3D& box)
	{
		m_box = box;
	}

	void OctreeComposite::Draw()
	{
		if (!s_drawLeavesOnly)
		{
			float c = 0.7f;
			glColor3f(c, c, c);
			glLineWidth(1);
			m_box.Draw();
		}
    
		for (unsigned int i = 0; i < m_children.size(); i++)
		{
			m_children[i]->Draw();
		}
	}

	void OctreeComposite::AddChild(Octree* pChild)
	{
		m_children.push_back(pChild);
	}

	OctreeLeaf::OctreeLeaf(const Tris& tris, const Box3D& box) 
		: m_tris(tris)
	{
		m_box = box;
	}

	void OctreeLeaf::Draw() 
	{
		//glDisable(GL_TEXTURE_2D);
		//glDisable(GL_LIGHTING);
    
		glColor3f(1, 1, 0);
		glLineWidth(3);
		m_box.Draw();
    
		//glPushMatrix();
		//	glBegin(GL_POINTS);
		//	glVertex3f(1, 1, 1);
		//	glVertex3f(2, 3, 1);
		//	glEnd();
		//glPopMatrix();


		//glBegin(GL_TRIANGLES);
		for (unsigned int i = 0; i < m_tris.size(); i++)
		{
			m_tris[i].Draw();
			//m_tris[i]->Draw();
		}
		//glEnd();

		//glEnable(GL_TEXTURE_2D);
		//glEnable(GL_LIGHTING);
	}
}