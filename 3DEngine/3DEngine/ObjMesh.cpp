#include "ObjMesh.h"
#include "MyGL.h"
#include "File.h"
#include "ObjMeshFunction.h"


namespace Engine
{
	bool ObjMesh::Load(const std::string& filename)
	{
		// Open the file

		File f;
		if (!f.OpenRead(filename))
		{
			return false;
		}

		// while not end of file
		std::string line;

		Group g(this);

		m_groups["default"] = g;
		Group* currentGroup = &m_groups["default"];

		// read the next line
		while(f.GetLine(&line))
		{
			// split the line
			Strings strs = Split(line, ' ');

			// decide what to do next depending on the
			// value of string[0]
			if (strs[0] == "v")
			{
				Vec3f v = ToVec3(strs);
				m_coords.push_back(v);
			}
			else if (strs[0] == "vn")
			{
				Vec3f v = ToVec3(strs);
				m_normals.push_back(v);
			}
			else if (strs[0] == "vt")
			{
				Vec2f v = ToVec2(strs);
				m_uvs.push_back(v);
			} 
			else if(strs[0] == "f")
			{
				Face f = ToFace(strs);
				currentGroup->m_faces.push_back(f);
			}
			else if (strs[0] == "g")
			{
				Group g(this);
				g.m_name = strs[1];
				m_groups[g.m_name] = g;
				currentGroup = &m_groups[g.m_name];
			}
			else if (strs[0] == "usemtl")
			{
				currentGroup->m_materialName = strs[1];
			}
			else if (strs[0] == "mtllib")
			{
				LoadMtl(strs[1]);
			}
		}

		//f.GetLine(&line);

		return true;
	}

	bool ObjMesh::LoadMtl(const std::string &filename)
	{
		File f;
		if (!f.OpenRead(filename))
		{
			return false;
		}
		std::string line;
		std::string matname;
		while (f.GetLine(&line))
		{
			Strings strs = Split(line, ' ');
			if (strs[0] == "newmtl")
			{
				matname = strs[1];
			}
			else if (strs[0] == "map_Kd")
			{
				TextureManager* tex = new TextureManager;
				tex->Load(strs[1]);
				ObjMaterial om;
				om.m_texture = tex;
				m_materials[matname] = om;
			}
		}
		return true;
	}

	void ObjMesh::Draw()
	{
		// For Each Group
		for(Groups::iterator it = m_groups.begin();
			it != m_groups.end();
			++it)
		{
			// Draw this group
			it->second.Draw();
		}
	}

	void Group::Draw()
	{
		// Set The material
		ObjMaterial mat = m_mesh->m_materials[m_materialName];
		if (mat.m_texture)
		{
			mat.m_texture->Draw();
		}
		//mat.m_material.UseThisMaterial();

		// Draw the Faces (triangles)
		glBegin(GL_TRIANGLES);
		// for each face
		for (unsigned int j = 0; j < m_faces.size(); j++)
		{
			Face& f = m_faces[j];

			// for each vertex, setting normals, texture coordinates and UVs
			for (int i = 0; i < 3; i++)
			{
				int normalIdx = f.m_normalIndex[i];
				Vec3f norm = m_mesh->m_normals[normalIdx];

				glNormal3f(norm.x, norm.y, norm.z);

				int uvIdx = f.m_uvIndex[i];
				Vec2f uv = m_mesh->m_uvs[uvIdx];
				glTexCoord2f(uv.x, uv.y);

				int texCoordIdX = f.m_pointIndex[i];
				Vec3f coord = m_mesh->m_coords[texCoordIdX];
				glVertex3f(coord.x, coord.y, coord.z);
			}
		}

		glEnd();
	}
}