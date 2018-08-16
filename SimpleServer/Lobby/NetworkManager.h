#pragma once
#include "../Socket/SocketUtil.h"
#include "ClientProxy.h"
#include<unordered_map>

class NetworkManager {
public:
	static NetworkManager* instance;
	bool StaticInit(uint16_t inPort);
	void onReceivedData(void* data, const SocketAddress& from);
	void SendData(const void* inData, int inLen, const SocketAddress& inTo);
private:
	NetworkManager();
	int newPlayerId;
	UDPSocketPtr udpSocket;
	std::unordered_map<SocketAddress, ClientProxyPtr> addressToClientMap;
};