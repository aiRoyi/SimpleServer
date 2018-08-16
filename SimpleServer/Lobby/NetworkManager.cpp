#include "NetworkManager.h"
#include "GamePeer.h"

NetworkManager* NetworkManager::instance;

NetworkManager::NetworkManager()
{
	newPlayerId = 1;
	UDPSocket::setRecvDataCallback(this, &NetworkManager::onReceivedData);
}

bool NetworkManager::StaticInit(uint16_t inPort)
{
	udpSocket = SocketUtil::CreateUDPSocket(INET);
	SocketAddress ownAddress(INADDR_ANY, inPort);
	udpSocket->Bind(ownAddress);
	if(udpSocket == nullptr)
	{
		return false;
	}
	if (udpSocket->SetNonBlockingMode(true) != NO_ERROR)
	{
		return false;
	}
	return true;
}

void NetworkManager::onReceivedData(void* data, const SocketAddress& from)
{
	if (addressToClientMap.find(from) != addressToClientMap.end())
	{
		ClientProxyPtr newClientProxy = std::make_shared<ClientProxy>(from, newPlayerId++);
		addressToClientMap[from] = newClientProxy;
		GamePeer* newPeer = newClientProxy->GetGamePeerInstance();
		newPeer->onConnected(newClientProxy);
	}
	auto user = addressToClientMap[from];
	auto peer = user->GetGamePeerInstance();
	peer->onRecieved(data);
}

void NetworkManager::SendData(const void* inData, int inLen, const SocketAddress& inTo)
{
	udpSocket->SendTo(inData, inLen, inTo);
}