#include "ClientProxy.h"
#include "GamePeer.h"
#include "../Socket/SocketAddress.h"

ClientProxy::ClientProxy(const SocketAddress& socketAddress, int userId)
{
	ClientProxy::mSocketAddress = socketAddress;
	ClientProxy::mUserId = userId;
	mGamePeer = nullptr;
}

GamePeer* ClientProxy::GetGamePeerInstance()
{
	if (mGamePeer == nullptr)
	{
		auto peer = GamePeer(mUserId);
		mGamePeer = peer.GetInstance();
	}
	return mGamePeer;
}