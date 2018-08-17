#pragma once
#include "../Messages/GameMessageManager.h"
#include "ClientProxy.h"

class GamePeer
{
public:
	GamePeer(int userId);
	~GamePeer();
	void onRecieved(void* data);
	void onConnected(ClientProxyPtr clientProxy);
	void onDisconnected();
	void SendGameMessage(GameMessage* message);
	GamePeer* GetInstance();
private:
	GamePeer* instance;
	int userId;
	ClientProxyPtr clientPtr;
};