#include "ProtobufSerializerUtil.h"
#include "../Protobuf/S2C/Text.pb.h"

const char* Serialize(GameMessage message) {
	if (ProtobufSerializerUtil::MessageSerializerLookups.find(message.gMessageType) != ProtobufSerializerUtil::MessageSerializerLookups.end())
	{
		return ProtobufSerializerUtil::MessageSerializerLookups[message.gMessageType](message);
	}
	else
	{
		return nullptr;
	}
}

const char* SerializeText(GameMessage message)
{
	MessageText* msg = (MessageText*)&message;
	Text proto;
	proto.set_text(msg->text);
	string outstr;
	proto.SerializeToString(&outstr);
	const char* out = outstr.c_str();
	return out;
}