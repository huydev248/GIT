#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include "TachBit.h"

void main()
{
	int16_t b = 0;
	int16_t t = 0;
	printf("Nhap vao so nguyen: \r\n");
	t = scanf("%d", &b);

	TachBit(b); 
}

