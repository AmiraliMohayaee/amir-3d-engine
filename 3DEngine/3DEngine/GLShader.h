#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <string>

namespace Engine
{
	class GLShader
	{
	public:
	  GLShader();
	  bool Create(const std::string& vertexSource, const std::string& fragmentSource);

	  bool Load(const std::string& vertexFile, const std::string& fragmentFile);

	  void UseThisShader();

	  void Set(const std::string& name, float f);

	private:
	  unsigned int m_program;
	};
}
#endif
