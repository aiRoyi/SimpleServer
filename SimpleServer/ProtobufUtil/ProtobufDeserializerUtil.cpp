#include "ProtobufDeserializerUtil.h";
#include "../Protobuf/S2C/Text.pb.h"
#include "../Messages/MessageText.h"


std::map<GameMessage::MessageType, std::function<GameMessage*(char*)>> ProtobufDeserializerUtil::MessageDeserializerLookups =
{
	{ GameMessage::TypeText, ProtobufDeserializerUtil::DeserializeProtoText },
};

GameMessage* ProtobufDeserializerUtil::Deserialize(char code, char* data) {
	try {
		GameMessage::MessageType type = static_cast<GameMessage::MessageType> (code);
		if (ProtobufDeserializerUtil::MessageDeserializerLookups.find(type) != ProtobufDeserializerUtil::MessageDeserializerLookups.end())
		{
			return ProtobufDeserializerUtil::MessageDeserializerLookups[type](data);
		}
	}
	catch(exception){

	}
}

GameMessage* ProtobufDeserializerUtil::DeserializeProtoText(char* data)
{
	MessageText msg;
	Text proto;
	proto.ParseFromArray(data, sizeof(data));
	msg.gMessageType = GameMessage::MessageType::TypeText;
	msg.text = proto.text();
	return &msg;
}