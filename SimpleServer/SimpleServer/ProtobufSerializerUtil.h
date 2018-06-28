#pragma once
#include <map>
#include "GameMessage.h"
#include <stdlib.h>
#include <functional>

namespace ProtobufSerializerUtil
{
	static std::map<MessageType, std::function<const char*(GameMessage)>> MessageSerializerLookups =
	{
		{TypeText, SerializeProtoText },
	};

	static const char* Serialize(GameMessage message);

	static const char* SerializeProtoText(GameMessage message);
}