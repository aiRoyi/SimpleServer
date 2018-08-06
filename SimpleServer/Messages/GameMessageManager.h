#pragma once
#include "GameMessage.h"

class GameMessageManager
{
public:

	GameMessageManager();
	virtual ~GameMessageManager();

	static void onReceiveData(void* data);

	static void onReceiveGameMessage(char code, char* message);
};

