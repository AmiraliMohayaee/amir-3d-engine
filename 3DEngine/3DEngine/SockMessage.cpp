#include "SockMessage.h"
#include "SDL.h"
#include "SDL_net.h"
#include <iostream>
#include <assert.h>

//
//
//namespace Engine
//{
//	#define SDL_reinterpret_cast(type, expression) reinterpret_cast<type>(expression)
//
//	SockMessage::SockMessage()
//	{
//
//	}
//
//	void SockMessage::Clear()
//	{
//
//	}
//
//	const unsigned char* SockMessage::GetData() const
//	{
//		return m_chars.data();
//	}
//
//	int SockMessage::GetLength() const
//	{
//		return m_chars.size();
//	}
//
//
//	bool SockMessage::ReadInt(int* result)
//	{
//		assert(m_readIndex + sizeof(int) <= m_chars.size());
//
//		if (m_readIndex + sizeof(int) > m_chars.size())
//		{
//			return false;
//		}
//	
//		//int diff = m_chars.size() - m_readIndex;
//
//	/*
//		if (diff < 4)
//		{
//			assert(0);
//			return false;
//		}*/
//
//		//int* i = (int*) (&(m_chars[m_readIndex]));
//
//		// Convert from network byte order to native endianness
//		*result = SDLNet_Read32(m_chars[m_readIndex]);
//		//m_readIndex += 4;
//		m_readIndex += sizeof(int);
//	
//		return true;
//	}
//
//	bool SockMessage::ReadFloat(float* result)
//	{
//		int i;
//		if (!ReadInt(&i))
//		{
//			return false;
//		}
//		*result = *((float*)&i);
//		return true;
//	}
//
//
//	bool SockMessage::ReadString(std::string* result)
//	{
//		// Read length of string (this could fail)
//		int len = 0;
//		if (!ReadInt(&len))
//		{
//			return false;
//		}
//
//		// Check that there are 'len' chracters
//		if (m_readIndex + len > (int)m_chars.size())
//		{
//			return false;
//		}
//	
//		// Append that many bytes to the string (this could fail as well)
//		const unsigned char* r = m_chars.data() + m_readIndex;
//		result->append(r, r + len);
//
//		// Advance the read pointer/index past the string data
//
//		return true;
//	}
//
//	bool SockMessage::WriteInt(int i)
//	{
//		SDLNet_Write32(i, &i);
//		unsigned char* chars = (unsigned char*)(&i);
//		m_chars.insert(m_chars.end(), chars, chars + 4);
//		return true;
//	}
//
//	bool SockMessage::WriteFloat(float f)
//	{
//		SDLNet_Write32(*((int*)(&f)), &f);
//		// casting to float
//		unsigned char* p = reinterpret_cast<unsigned char*>(&f);
//	
//		m_chars.insert(m_chars.end(), p, p + sizeof(float));
//
//		return true;
//	}
//
//	bool SockMessage::WriteString(const std::string& str)
//	{
//		// Write the length of the string - this is an int
//		WriteInt(str.size());
//	
//	
//		// Append the actual string data to m_chars
//		m_chars.insert(m_chars.begin(), 
//			str.begin(),
//			str.end());
//
//		m_chars.insert(m_chars.begin(), 
//			str.data(),
//			str.data() + str.size());
//
//		return true;
//	}
//
//	void SockMessage::Append(unsigned char* begin, unsigned char* end)
//	{
//		m_chars.insert(m_chars.end(), begin, end);
//
//		for (int i = 0; begin != end; i++)
//		{
//			m_chars.push_back(*begin);
//		}
//	}
//}