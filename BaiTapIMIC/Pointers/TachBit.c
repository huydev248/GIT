#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

#include "TachBit.h"

void TachBit(int16_t x)
{
	int8_t* x_low = &x;
	int8_t* x_high = x_low + 1;

	printf("X low: 0x%2X\r\n", *x_low);
	printf("X high: 0x%2X\r\n", *x_high);
}

