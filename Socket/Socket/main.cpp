#define _CRT_SECURE_NO_WARNINGS
#include "Socket.h"
#include "AWS_S3.h"

int main()
{
	//Class Socket
	/*Socket test((char*)"192.168.1.25", 2222);
	test.Send((char*)"Send from my app\r\n");
	char buff[1024];
	test.Recv(buff, sizeof(buff));*/

	//Inheritance class Socket
	AWS_S3 imic;

	Socket server(1234);

	while (1)
	{
		char data[1024];
		memset(data, 0, sizeof(data));
		server.waitingData(data, sizeof(data));
		printf("%s", data);
		for (int i = 3; i < strlen(data); i++)
		{
			if (data[i] == 'F' && data[i - 1] == 'F' && data[i - 2] == '0')
			{
				imic.put((char*)"helloWorld.txt", (char*)"LED_OFF", 7);
				break;
			}
			else if (data[i] == 'N' && data[i - 1] == 'O')
			{
				imic.put((char*)"helloWorld.txt", (char*)"LED_ON", 6);
				break;
			}
		}
	}


	/*char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	imic.get((char*)"helloWorld.txt", buffer, sizeof(buffer));
	printf("%s\r\n", buffer);


	char* data = (char*)"Xin chao";
	imic.put((char*)"test.txt", data, strlen(data));*/
	//imic.putFile((char*)"test1.txt");


	/*char buffer[1024];
	memset(buffer, 0, sizeof(buffer));
	imic.get((char*)"test_huy.png", buffer, sizeof(buffer), (char*)"newFile.png");*/
	return 0;
}