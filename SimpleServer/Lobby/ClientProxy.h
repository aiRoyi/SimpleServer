#pragma once
#include <memory>

#include "../Socket/SocketAddress.h"

class GamePeer;
class ClientProxy
{
public:
	ClientProxy(const SocketAddress& socketAddress,  int userId);
	int	GetPlayerId() const { return mUserId; }
	const SocketAddress& GetSocketAddress() const { return mSocketAddress; }

	GamePeer* GetGamePeerInstance();

private:
	SocketAddress mSocketAddress;
	int mUserId;
	GamePeer* mGamePeer;
};

typedef std::shared_ptr<ClientProxy> ClientProxyPtr;