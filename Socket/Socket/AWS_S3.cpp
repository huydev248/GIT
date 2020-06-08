#define _CRT_SECURE_NO_WARNINGS
#include "AWS_S3.h"

AWS_S3::AWS_S3():Socket((char*)"52.219.128.83", 80)
{
}

int stringLen(char* string)
{
	int len = 0;
	while (string[len++] != 0);
	return len - 1;
}

int strngFind(string stringSrc, string stringFind)
{
	int i = 0;
	for (i = 0; i < stringLen(stringSrc) - stringLen(stringFind); i++)
	{
		int j = 0;
		for (j = 0; j < stringLen(stringFind); j++)
		{
			if (stringFind[j] != stringSrc[i + j])break;
		}
		if (j == stringLen(stringFind))break;
	}
	if (i == stringLen(stringSrc) - stringLen(stringFind))return -1;
	return i;
}

int status(int index, char* buff, int strlen, char* arr)
{
	int i = index + strlen;
	int res = 0;
	int j;
	printf("Content-Length: ");
	while (buff[i] != '\r')
	{
		printf("%c", buff[i]);
		for (j = 0; j <= strlen; j++)
		{
			arr[j] = buff[i];
		}
		res = res * 10 + (buff[i] - '0');
		i++;
	}
	printf("\n");
	printf("Length: %d", res);
	return res;
}

int Get_Content_Length(char* data)
{
	char arr[100];
	string strFind = (char*)"Content-Length: ";
	int length = stringLen(strFind);
	int result = strngFind(data, strFind);
	int intLen = status(result, data, length, arr);
	return intLen;
}

void AWS_S3::get(char* nameFile, char* buff, int buffLen, char* imgName)
{
	char data_send[1024];
	memset(data_send, 0, sizeof(data_send));
	sprintf(data_send, "GET /%s HTTP/1.1\r\nHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\n\r\n", nameFile);
	//printf("data send: %s", data_send);
	Send(data_send);
	char header[1024];
	int count = 0;
	memset(header, 0, sizeof(header));
	while (1)
	{
		Recv(header + count, 1);
		if (count >= 3)
		{
			if (header[count] == '\n' && header[count-1] == '\r' && header[count-2] == '\n' && header[count-3] == '\r')
			{
				break;
			}
		}
		count++;
	}
	printf("Header: %s\r\n", header);

	int contenLen = Get_Content_Length(header);
	FILE* imgFile = fopen(imgName, "w+b");
	char data_img_char = 0;
	for (int i = 0; i < contenLen; i++)
	{
		Recv(&data_img_char, 1);
		fputc(data_img_char, imgFile);
	}
	fclose(imgFile);
}


void AWS_S3::put(char* nameFile, char* data, int dataLen)
{
	char data_send[1024];
	sprintf(data_send, "PUT /%s HTTP/1.1\r\nHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\nContent-Length:%d\r\n\r\n%s",nameFile, dataLen, data);
	printf("data_send: %s\r\n", data_send);
	Send(data_send);
	/*char temp[1024];
	memset(temp, 0, sizeof(temp));
	Recv(temp, sizeof(temp));
	printf("temp: %s\r\n", temp);*/
}

void AWS_S3::putFile(char* nameFile)
{
	FILE* file = fopen(nameFile, "a+b");
	int sizeFile = 0;
	while (true)
	{
		if (fgetc(file) == EOF)break;
		sizeFile++;
	}
	fclose(file);
	printf("Size of file: %d\r\n", sizeFile);

	char header[256];
	memset(header, 0, sizeof(header));
	sprintf(header, "PUT /%s HTTP/1.1\r\nHost: imic-backet-s3.s3-ap-southeast-1.amazonaws.com\r\nContent-Length:%d\r\n\r\n", nameFile, sizeFile);
	//printf("%s",header);
	Send(header);

	file = fopen(nameFile, "a+b");
	char temp = 0;
	for (int i = 0; i < sizeFile; i++)
	{
		temp = fgetc(file);
		SendOneByte(temp);
	}

	/*char dataRecv[1024];
	memset(dataRecv, 0, sizeof(dataRecv));
	Recv(dataRecv, sizeof(dataRecv));
	printf("dataRecv: %s\r\n", dataRecv);*/
}