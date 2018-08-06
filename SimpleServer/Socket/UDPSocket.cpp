#include "UDPSocket.h"
#include "SocketUtil.h"


CallbackRecvData UDPSocket::recvDataCallback = NULL;

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
		recvDataCallback(inBuffer);
		return readByteCount;
	}
	else
	{
		SocketUtil::ReportError("UDPSocker::ReceiveFrom");
		return -SocketUtil::GetLastError();
	}
}

void UDPSocket::setRecvDataCallback(CallbackRecvData callback)
{
	recvDataCallback = callback;
}


UDPSocket::~UDPSocket()
{
	closesocket(mSocket);
}