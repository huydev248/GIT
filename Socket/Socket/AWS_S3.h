#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Socket.h"

typedef char* string;
class AWS_S3: public Socket 
{
public:
	AWS_S3();
	void get(char* nameFile, char* buff, int buffLen, char* imgName);
	void put(char* nameFile, char* data, int dataLen);
	void putFile(char* nameFile);
};
int stringLen(char* string);
int strngFind(string stringSrc, string stringFind);
int status(int index, char* buff, int strlen, char* arr);
