#include "GameLobby.h"


GameLobby::GameLobby()
{
	newRoomId = 1;
}

GameLobby::~GameLobby()
{
}

const Room* GameLobby::CreateRoom(GamePeer* creator)
{
	return Room::Create(newRoomId, creator);
}