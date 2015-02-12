#include "Log.h"
#include <fstream>

namespace Engine
{
	void Engine::Log(const std::string& l)
	{
		static std::ofstream log;

		if(!log.is_open())
		{
			log.open("log.txt", std::ios::trunc);
			if(!log.is_open())
				return;
		}
		log << l << std::endl;
	}
}