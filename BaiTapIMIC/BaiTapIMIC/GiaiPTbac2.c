#include <stdio.h>
#include <math.h>
#include "GiaiPTbac2.h"


void PTbac2(int a, int b, int c)
{
	float x = 0, x1 = 0, x2 = 0;
	float delta = 0;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("Phuong trinh vo so nghiem.");
			}
			else
			{
				printf("Phuong trinh vo nghiem.");
			}
		}
		else
		{
			printf("Phuong trinh co 1 nghiem: %0.2f.", -c / b);
		}
	}
	else
	{
		delta = b * b - 4 * a * c;
		x = -b / (2 * a);
		if (delta == 0)
		{
			printf("Phuong trinh co 1 nghiem kep: %0.2f", x);
		}
		else if (delta < 0)
		{
			printf("Phuong trinh vo nghiem.");
		}
		else
		{
			x1 = -b + sqrt(delta) / 2 * a;
			x2 = -b - sqrt(delta) / 2 * a;
			printf("\nPhuong trinh co 2 nghiem phan biet.\r\n");
			printf("\nNghiem x1: %.2f\r\n", x1);
			printf("\nNghiem x2: %.2f\r\n", x2);
		}
	}
}