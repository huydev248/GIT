#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void PTbac2 (int a, int b, int c);

void main()
{
	PTbac2(1, -5, 6);
}

void PTbac2(int a, int b, int c)
{
	float x = 0, x1 = 0, x2 = 0;
	float d = 0;
	
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("Phuong trinh vo so nghiem");
			}
			else 
			{
				printf("Phuong trinh vo nghiem");
			}
		}
		else
		{
			printf("Phuong trinh co 1 nghiem duy nhat: %0.2d\n", -c/b);
		}
	}
	else
	{
		d = b*b - 4*a*c;
		if (d<0)
		{
			printf("Phuong trinh vo nghiem");
		}
		else if (d == 0)
		{
			x = -b/2*a;
			printf("Phuong trinh co nghiem kep: %0.2f", x);
		}
		else
		{
			x1 = ((-b) + sqrt(d)) / 2*a;
			x2 = ((-b) - sqrt(d)) / 2*a;
			printf("Phuong trinh co 2 nghiem phan biet lan luot la: %.2f, %0.2f\n", x1, x2);
		}
	}
}
			
		
				