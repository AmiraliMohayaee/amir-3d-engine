#ifndef SOCK_MESSAGE_H_INCLUDED 
#define SOCK_MESSAGE_H_INCLUDED


#include <iostream>
#include <vector>
#include <memory> // Used for shared_ptr
//
//namespace Engine
//{
//	class SockMessage
//	{
//	public:
//		friend class Socket;
//
//		SockMessage();
//		//~SockMessage();
//		virtual ~SockMessage() {}
//
//		void Clear();
//		const unsigned char* GetData() const;
//		int GetLength() const;
//
//		bool ReadInt(int* i);
//		bool ReadFloat(float* result);
//		bool ReadString(std::string* result);
//
//		bool WriteInt(int);
//		bool WriteFloat(float);
//		bool WriteString(const std::string& str);
//
//		void Append(unsigned char* begin, unsigned char* end);
//
//	private:
//		typedef std::vector <unsigned char> Chars;
//		Chars m_chars;
//		int m_readIndex;
//	};
//}

#endif