#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

namespace Engine
{
	class File
	{
	public:
		bool OpenRead(const std::string& filename);
		bool GetInteger(int* pIntResult);
		bool GetFloat(float* pFloatResult);
		bool GetLine(std::string* pStringResult);

	private:
		std::ifstream m_ifstream; // ifstream is used for reading from a file
	};
}

#endif