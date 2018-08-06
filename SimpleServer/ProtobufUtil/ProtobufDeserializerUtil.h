#pragma once
#include <map>
#include "../Messages/GameMessage.h"
#include <stdlib.h>
#include <functional>


namespace ProtobufDeserializerUtil
{
	extern std::map<GameMessage::MessageType, std::function<GameMessage*(char*)>> MessageDeserializerLookups;

	GameMessage* Deserialize(char code, char* data);

	GameMessage* DeserializeProtoText(char* data);
}