#pragma once
#include <map>
#include "../Messages/GameMessage.h"
#include <stdlib.h>
#include <functional>

namespace ProtobufSerializerUtil
{
	const char* Serialize(GameMessage* message);

	const char* SerializeProtoText(GameMessage* message);

	extern std::map<GameMessage::MessageType, std::function<const char*(GameMessage*)>> MessageSerializerLookups;
};