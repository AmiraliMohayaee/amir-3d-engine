#include "FileHeaderReader.h"
#include "libsndfile/include/sndfile.h"
#include <iostream>


namespace Engine
{
	bool PrintFileHeader(const std::string& filePath, const int MAX_CHANNELS)
	{
		SF_INFO info;
		SNDFILE* file = sf_open(filePath.c_str(), SFM_READ, &info);

		if(!file) 
		{
			std::cout << sf_strerror(nullptr) << std::endl;
			return false;
		}

		if(info.channels > MAX_CHANNELS) 
		{
			std::cout << "number of channels(" << info.channels << ") exceeds max number of channels(" << MAX_CHANNELS << ")";
			if(!sf_close(file))
			{
				std::cout << "unable to close file " + filePath << std::endl;
				return false;
			}
			return false;
		}

		std::cout << "file name:" << filePath << std::endl;
		std::cout << "frames:" << info.frames << std::endl;
		std::cout << "channels:" << info.channels << std::endl;
		std::cout << "sample rate:" << info.samplerate << std::endl;
		std::cout << "format:" << info.format << std::endl;

		if(!sf_close(file))
		{
			std::cout << "unable to close file " + filePath << std::endl;
			return false;
		}

		return true;
	}
}