#include "File.h"
#include <string>
#include <assert.h>


namespace Engine
{
	bool File::OpenRead(const std::string& filename)
	{
		//m_ifstream.open(filename.c_str());
		m_ifstream.open(filename.c_str(), 
			std::ifstream::in);

		return (m_ifstream.is_open());
	}

	bool File::GetInteger(int* result)
	{		
		std::string s;
		if (!GetLine(&s))
		{
			return false;
		}

		// atoi() convert strings to integers
		*result = atoi(s.c_str());
		return true;
	}

	bool File::GetFloat(float* result)
	{
		// function should look identical to the GetInteger func
		// atof() converts ints to flaots
		std::string s;
		if (!GetLine(&s))
		{
			return false;
		}

		*result = (float)atof(s.c_str());
		return true;
	}

	bool File::CloseReadStream()
	{
		m_ifstream.close();
		return true;
	}

	// Only reads from a file
	bool File::GetLine(std::string* result)
	{
		while (true)
		{
			std::string str;

			if(!m_ifstream.good())
			{
				return false;
			}
			std::getline(m_ifstream, str); // (file, string line)
			if (str.empty() || 
				str[0] == '#') // # lines are comments
			{
				continue;
			}
			*result = str;
			return true;
		}
	}

	// Creates new text file 
	//bool File::OpenWrite(const std::string& filename)
	//{
	//	//m_fstream.open(filename);
	//	m_ofstream.open(filename,
	//		std::ofstream::out);
	//	// Error checking
	//	if (m_ofstream.is_open)
	//	{
	//		// File is open for writing

	//		m_ofstream << "Test text" << "\n";

	//		// Write stuff here
	//	}
	//	else
	//	{
	//		std::cout << "Stream file writing failed.\n";
	//		CloseWriteStream();
	//		return false;
	//	}
	//}


	//bool File::CloseWriteStream()
	//{
	//	m_ofstream.close();
	//}
}