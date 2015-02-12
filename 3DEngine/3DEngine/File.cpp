#include "File.h"

#include <fstream>
#include <iostream>
#include <string>

bool Engine::File::OpenRead(const std::string& filename)
{
	m_ifstream.open(filename.c_str());

	return (m_ifstream.is_open());
}

bool Engine::File::GetInteger(int* result)
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

bool Engine::File::GetFloat(float* result)
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

bool Engine::File::GetLine(std::string* result)
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