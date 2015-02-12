#ifndef OBJMESH_H
#define OBJMESH_H

#include <string>
#include "ObjMeshFunction.h"
#include "Vec2.h"
#include "Vec3.h"
#include "TextureManager.h"

namespace Engine
{
	struct ObjMaterial
	{
		ObjMaterial() : m_texture(0) {}
		//UseTexture();
		//UseMaterial();

		TextureManager* m_texture;
		//Material m_materials;
	};
	typedef std::map<std::string, ObjMaterial> MatMap;

	class ObjMesh
	{
	public:
		bool Load(const std::string& filename);

		void Draw();

		bool LoadMtl(const std::string &filename);

	private:
		Groups m_groups;
		Vec3s m_coords;
		Vec2s m_uvs;
		Vec3s m_normals;

		friend struct Group;

		friend class CollisionMesh;

		MatMap m_materials;
	};
}

#endif