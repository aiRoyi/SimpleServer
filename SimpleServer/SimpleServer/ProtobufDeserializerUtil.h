#pragma once
#include <map>
#include "GameMessage.h"
#include <stdlib.h>
#include <functional>


namespace ProtobufDeserializerUtil
{
	static std::map<MessageType, std::function<GameMessage(char*, char*)>> MessageDeserializerLookups =
	{
	};

	static GameMessage Deserialize(char* type, char* data);
}