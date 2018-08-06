#include "GameMessageManager.h"
#include "../Socket/UDPSocket.h"
#include "../ProtobufUtil/ProtobufDeserializerUtil.h"


GameMessageManager::GameMessageManager()
{
	UDPSocket::setRecvDataCallback(onReceiveData);
}

void GameMessageManager::onReceiveData(void* data)
{
	char code;
	char* type = "";
	char* message = "";
	std::memcpy(type, data, 4);
	std::memcpy(message, data, sizeof(data));
	code = type[0];
	onReceiveGameMessage(code, message);
}

void GameMessageManager::onReceiveGameMessage(char code, char* data)
{
	GameMessage* message = ProtobufDeserializerUtil::Deserialize(code, data);
	GameMessage::MessageType type = message->gMessageType;
}

GameMessageManager::~GameMessageManager(){}