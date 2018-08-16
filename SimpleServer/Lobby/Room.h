#pragma once
#include<vector>
#include "GamePeer.h"

class Room
{
public:

	Room();
	~Room();
	void GetMembers();
	void onJoinRoom();
	void Broadcast();
private:
	int roomId;
	std::vector<GamePeer*> members;
};

