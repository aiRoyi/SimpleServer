// SimpleServer.cpp : Defines the entry point for the console application.
//

#include "WinSock2.h"
#include "../Protobuf/S2C/Text.pb.h"
#include "../Socket/UDPSocket.h"
#include "../Socket/SocketUtil.h"
#include "../Messages/MessageText.h"
#include "../ProtobufUtil/ProtobufSerializerUtil.h"

using namespace std;


int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* ʹ��Windef.h�е� MAKEWORD(lowbyte, highbyte) �궨�� */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* �Ҳ���Winsock DL L.*/
		printf("WSAStartup failed witherror: %d\n", err);
		return 1;
	}

	/*Text test_text;
	
	test_text.set_text("test");

	string outstr;
	test_text.SerializeToString(&outstr);
	const char* out = outstr.c_str();*/

	MessageText message;
	message.text = "test";
	const char* out = ProtobufSerializerUtil::Serialize(&message);


	sockaddr_in inSockAddr;
	memset(&inSockAddr, 0, sizeof(sockaddr_in));
	inSockAddr.sin_family = AF_INET;
	inSockAddr.sin_addr.S_un.S_un_b.s_b1 = 127;
	inSockAddr.sin_addr.S_un.S_un_b.s_b2 = 0;
	inSockAddr.sin_addr.S_un.S_un_b.s_b3 = 0;
	inSockAddr.sin_addr.S_un.S_un_b.s_b4 = 1;
	inSockAddr.sin_port = htons(48000);
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	SocketAddress addr(*((sockaddr*)&inSockAddr));
	
	//SocketAddress addr = SocketAddress(inet_addr("127.0.0.1"), 48000);
	
	UDPSocketPtr udpPtr = SocketUtil::CreateUDPSocket(SocketAddressFamily::INET);
	int sent = udpPtr->SendTo(out, sizeof(GameMessage), addr);
	
	WSACleanup();
    return 0;
}