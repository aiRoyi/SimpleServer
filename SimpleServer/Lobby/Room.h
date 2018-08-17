#pragma once
#include<vector>
#include "GamePeer.h"

class Room
{
public:
	static Room* instance;
	Room(int id);
	~Room();
	std::vector<GamePeer*> GetMembers();
	void onJoinRoom(GamePeer* peer);
	void Broadcast(GameMessage* message);
	void onPeerDisconnected(GamePeer* peer);
	static const Room* Create(int id, GamePeer* creator);
private:
	int roomId;
	std::vector<GamePeer*> roomMembers;
};

