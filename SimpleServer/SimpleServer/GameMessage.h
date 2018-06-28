#pragma once

class GameMessage
{
public:
	enum MessageType {
		TypeText = 0,
	};

	GameMessage::MessageType gMessageType;
	GameMessage(GameMessage::MessageType type);
	virtual ~GameMessage();

};


