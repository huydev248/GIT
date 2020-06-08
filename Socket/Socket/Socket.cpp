#define _CRT_SECURE_NO_WARNINGS
#include "Socket.h"
#include <stdio.h>

Socket::Socket(int port)
{
	printf("Initialising Winsock...\r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d\r\n", WSAGetLastError());
	}

	printf(" Initialised.\r\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d\r\n", WSAGetLastError());
	}

	printf(" Socket created.\r\n");

	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	bind(s, (struct sockaddr*) & server, sizeof(struct sockaddr));
}


void Socket::waitingData(char* dataRecv, int sizeData)
{
	listen(s, 10);
	struct sockaddr_in client;
	int lenSockAddr = sizeof(struct sockaddr);
	SOCKET sock = accept(s, (struct sockaddr*) &client, &lenSockAddr);

	char bodyRecv[1024];
	memset(dataRecv, 0, sizeData);

	recv(sock, dataRecv, sizeData, 0);

	//printf("data: %s\r\n", dataRecv);
	char* dataSend = (char*)"200 OK";
	send(sock, dataSend, strlen(dataSend), 0);
	closesocket(sock);
}


Socket::Socket(char* Server_IP, int port)
{
	printf("Initialising Winsock...\r\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf(" Failed.Error Code : %d\r\n", WSAGetLastError());
	}
	else 
	{
		printf("Initialised.\r\n");
	}

		//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d\r\n", WSAGetLastError());
	}
	else
	{
		printf(" Socket created.\r\n");
		server.sin_addr.s_addr = inet_addr(Server_IP);
		server.sin_family = AF_INET;
		server.sin_port = htons(port);
	}

	//Connect to remote server
	if (connect(s, (struct sockaddr*) & server, sizeof(server)) < 0)
	{
		printf("connect error\r\n");
	}

	printf("Connected\r\n");
}

int Socket::Send(char* data)
{
	int size = 0;
	while (data[size++] != 0);
	return send(s, data, size - 1, 0);
}

int Socket::Recv(char* buff, int size)
{
	return recv(s, buff, size, 0);
}

int Socket::SendOneByte(char data)
{
	return send(s, &data, 1, 0);
}
