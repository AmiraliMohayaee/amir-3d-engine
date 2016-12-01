#pragma once

#include <string>
#include <fstream>
#include <iostream>


namespace Engine
{
	class File
	{
	public:
		//File();

		// Reading functions
		bool OpenRead(const std::string& filename);
		bool GetInteger(int* pIntResult);
		bool GetFloat(float* pFloatResult);
		bool GetLine(std::string* pStringResult);
		bool CloseReadStream();

		// To-Do: Finish these
		// Text File creation and/or writing functions
		//bool OpenWrite(const std::string& filename);
		//bool CloseWriteStream();


	protected:
		//std::fstream &m_fstream;	// Used for both reading and writing
		//std::basic_fstream<std::fstream> m_basicFstream;
		std::ifstream m_ifstream; // ifstream is used for inputting into a file
		std::ofstream m_ofstream; // For outputing 
	};
}