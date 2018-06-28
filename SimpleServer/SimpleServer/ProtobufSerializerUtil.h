#pragma once
#include <map>
#include "GameMessage.h"
#include <stdlib.h>
#include <functional>

namespace ProtobufSerializerUtil
{
	static const char* Serialize(GameMessage message);

	static const char* SerializeProtoText(GameMessage message);

	static std::map<GameMessage::MessageType, std::function<const char*(GameMessage)>> MessageSerializerLookups =
	{
		{ GameMessage::TypeText, SerializeProtoText },
	};
}