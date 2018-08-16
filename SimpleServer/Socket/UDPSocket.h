#include "SocketAddress.h"
#include "WinSock2.h"
#include <memory>

#ifndef UDPSocket_H
#define UDPSocket_H

class NetworkManager;
typedef void(NetworkManager::*CallbackRecvData)(void* data, const SocketAddress& from);

class UDPSocket
{
public:
	~UDPSocket();
	int Bind(const SocketAddress& inToAddress);
	int SendTo(const void* inData, int inLen, const SocketAddress& inTo);
	int ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom);
	int SetNonBlockingMode(bool inShouldBeNonBlocking);
	static void setRecvDataCallback(NetworkManager* ptr, CallbackRecvData callback);
private:
	friend class SocketUtil;
	static CallbackRecvData	recvDataCallback;
	static NetworkManager*		recvDataObj;
	UDPSocket(SOCKET inSocket): mSocket(inSocket){}
	SOCKET mSocket;
};
typedef std::shared_ptr<UDPSocket> UDPSocketPtr;

#endif
