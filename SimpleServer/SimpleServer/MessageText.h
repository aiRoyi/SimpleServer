#pragma once
#include <string>
#include "GameMessage.h"

using namespace std;

class MessageText: public GameMessage
{
public:
	MessageText() : GameMessage(TypeText){}
	~MessageText();
	string text;
};
