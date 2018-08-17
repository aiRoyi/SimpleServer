#include "Room.h"

Room* Room::instance;

Room::Room(int id)
{
	roomId = id;
	roomMembers = std::vector<GamePeer*>();
	instance = this;
}


Room::~Room()
{
}

std::vector<GamePeer*> Room::GetMembers()
{
	return Room::roomMembers;
}

void Room::onJoinRoom(GamePeer* peer)
{
	roomMembers.push_back(peer);
}

void Room::Broadcast(GameMessage* message)
{
	for (GamePeer* peer : roomMembers)
	{
		peer->SendGameMessage(message);
	}
}

void Room::onPeerDisconnected(GamePeer* peer)
{
	//remove(members.begin, members.end, peer);
}

const Room* Room::Create(int id, GamePeer* creator)
{
	Room::Room(id);
	instance->onJoinRoom(creator);
	return instance;
}