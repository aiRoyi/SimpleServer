#pragma once
#include "GameMessage.h"
#include "../ProtobufUtil/ProtobufDeserializerUtil.h"
#include "../ProtobufUtil/ProtobufSerializerUtil.h"
#include "../Lobby/GamePeer.h"
#include "../Lobby/NetworkManager.h"

class GameMessageManager
{
public:

	GameMessageManager();

	static void onReceiveData(void* data);

	static void onReceiveGameMessage(char code, char* message);

	static void SendGameMessage(GameMessage* message, const SocketAddress& addr);
};

