#include "UDPSocket.h"
#include "SocketUtil.h"
#include "../Lobby/NetworkManager.h"

CallbackRecvData	UDPSocket::recvDataCallback = NULL;
NetworkManager*		UDPSocket::recvDataObj = NULL;

int UDPSocket::Bind(const SocketAddress& inBindAdress)
{
	int err = bind(mSocket, &inBindAdress.mSockAddr, inBindAdress.GetSize());
	if (err != 0)
	{
		SocketUtil::ReportError("UDPSocket::Bind");
		return SocketUtil::GetLastError();
	}
	return NO_ERROR;
}

int UDPSocket::SendTo(const void* inData, int inLen, const SocketAddress& inTo)
{
	int byteSentCount = sendto(mSocket, static_cast<const char*>(inData), inLen, 0, &inTo.mSockAddr, inTo.GetSize());
	if (byteSentCount >= 0)
	{
		return byteSentCount;
	}
	else
	{
		//return error as negative number
		SocketUtil::ReportError("UDPSocket::SendTo");
		return -SocketUtil::GetLastError();
	}
}

int UDPSocket::ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom)
{
	int fromLength = outFrom.GetSize();
	int readByteCount = recvfrom(mSocket, static_cast<char*>(inBuffer), inLen, 0, &outFrom.mSockAddr, &fromLength);
	if (readByteCount >= 0)
	{

		(recvDataObj->*recvDataCallback)(inBuffer, outFrom);
		return readByteCount;
	}
	else
	{
		SocketUtil::ReportError("UDPSocker::ReceiveFrom");
		return -SocketUtil::GetLastError();
	}
}

int UDPSocket::SetNonBlockingMode(bool inShouldBeNonBlocking)
{
	u_long arg = inShouldBeNonBlocking ? 1 : 0;
	int result = ioctlsocket(mSocket, FIONBIO, &arg);
	if (result == SOCKET_ERROR)
	{
		SocketUtil::ReportError("UDPSocket::SetNonBlockingMode");
		return SocketUtil::GetLastError();
	}
	else
	{
		return NO_ERROR;
	}
}

void UDPSocket::setRecvDataCallback(NetworkManager* ptr, CallbackRecvData callback)
{
	recvDataObj = ptr;
	recvDataCallback = callback;
}


UDPSocket::~UDPSocket()
{
	closesocket(mSocket);
}