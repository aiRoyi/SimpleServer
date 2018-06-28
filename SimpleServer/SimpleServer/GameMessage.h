#pragma once
#include <string>

using namespace std;

class GameMessage
{
public:
	MessageType gMessageType;
	GameMessage(MessageType type);
	virtual ~GameMessage();
};

enum MessageType {
	TypeText = 0,
};

class MessageText : GameMessage {
public:
	string text;
};


