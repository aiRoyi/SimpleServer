#pragma once
#include "Room.h"

class  GameLobby
{
public:
	 GameLobby();
	~ GameLobby();
	const Room* CreateRoom(GamePeer* creator);

private:
	std::vector<GamePeer*> lobbyMembers;
	std::vector<Room*> lobbyRooms;
	int newRoomId;
};
