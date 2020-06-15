#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma once
#include <stdint.h>
#include <stdio.h>
#include "Ws2tcpip.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library
typedef char* string;

class Socket
{
public:
	Socket(int port);
	Socket(char* Server_IP, int port);
	int Send(char* data);
	int Recv(char* buff, int size);
	int SendOneByte(char data);
	void waitingData(char* dataRecv, int sizeData);
private:
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
};

