#pragma once
#include "Winsock2.h";
//#include "Ws2tcpip.h"
//#include <stdint.h>
//#pragma comment(lib,"ws2_32.lib") //Winsock Library
ref class SocketWindows
{
public:
	SocketWindows(char* ip_server, int port); //with 2 argument, we set socket as client
	//SocketWindows(int port);				   //with 1 argument, we set socket as server
private:
	//struct sockaddr_in server;
	//WSADATA wsa;
	//SOCKET s;
	//char dstAddr[14];
	//char data2Send[1024];
};

