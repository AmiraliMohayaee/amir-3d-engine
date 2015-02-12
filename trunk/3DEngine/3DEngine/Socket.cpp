#include "Socket.h"

	
//
//namespace Engine
//{
//	#define SDL_reinterpret_cast(type, expression) reinterpret_cast<type>(expression)
//
//	Socket::Socket()
//	{
//		m_sockSet = SDLNet_AllocSocketSet(1);
//		//SDLNet_FreeSocketSet(m_sockSet);
//	}
//
//	Socket::Socket(TCPsocket sock)
//	{
//		m_sockSet = SDLNet_AllocSocketSet(1);
//		m_sock = sock;
//		if (sock)
//		{
//			SDLNet_TCP_AddSocket(m_sockSet, m_sock);
//		}
//	}
//
//	Socket::~Socket()
//	{
//		SDLNet_TCP_DelSocket(m_sockSet, m_sock);
//		SDLNet_TCP_Close(m_sock);
//		SDLNet_FreeSocketSet(m_sockSet);
//	}
//
//	bool Socket::Send(const SockMessage& sm)
//	{
//		// Use SDLNet_TCP_Send() for sending data
//		//assert(m_tcpSocket);
//
//		//bool b = Load();
//		//assert(b);
//
//		int len = sm.GetLength();
//		const unsigned char* data = sm.GetData();
//
//		int result = SDLNet_TCP_Send(m_sock, data, len);
//		if (result != len)
//		{
//			std::cout << "Error sending: " << SDLNet_GetError() << "\n";
//			return false;
//		}
//
//		return true;
//	}
//
//	bool Socket::HasData()
//	{
//		int numReady = SDLNet_CheckSockets(m_sockSet, 0);
//		return (numReady > 0);
//	}
//
//
//	bool Socket::Recv(SockMessage* sm)
//	{
//		// Read data from socket
//		static const int MAXLEN = 2000;
//		char msgrec[MAXLEN];
//
//		//msgrec[MAXLEN] = 0;
//		while (HasData())
//		{
//			int result = SDLNet_TCP_Recv(m_sock, msgrec, MAXLEN);
//			if (result <= 0)
//			{
//				//failed
//				std::cout << "Failed";
//				return false;
//			}
//			else
//			{
//				msgrec[result] = 0;
//				std::cout << "Got this from client:" << msgrec << "\n";
//			}
//
//			// Append data to the SockMessage
//			sm->Append((unsigned char*)msgrec, (unsigned char*)msgrec + result);
//
//			// Keep going until no more data is on socket
//		}
//
//		return true;
//	}
//}