#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "MyGL.h"
#include <string>
#include <fstream>


namespace Engine
{
	class TextureManager
	{
	public:
		TextureManager();
		bool Load(const std::string& filename);
		void Draw();
		void Update();
		void EnableSphereMap();

	private:
		int width;
		int height;
		GLuint texId;
		int format;
		int data;
		//std::ifstream m_ifstream;
	};
}

#endif