#include "GamePeer.h"

GamePeer::GamePeer(int userId)
{
	GamePeer::userId = userId;
	GamePeer::instance = this;
	clientPtr = nullptr;
	//UDPSocket::setRecvDataCallback(onRecieved);
}

GamePeer::~GamePeer()
{

}

void GamePeer::onConnected(ClientProxyPtr clientProxy)
{
	clientPtr = clientProxy;
}

void GamePeer::onDisconnected()
{

}

void GamePeer::onRecieved(void* data)
{
	GameMessageManager::onReceiveData(data);
}

void GamePeer::SendData(GameMessage* message, int userId)
{
	const SocketAddress& address = clientPtr->GetSocketAddress();
	GameMessageManager::SendGameMessage(message, address);
}

GamePeer* GamePeer::GetInstance()
{
	return GamePeer::instance;
}