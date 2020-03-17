#include<stdio.h>

int x, y;
void main()
{
printf("\nGia tri x=%6d, y=%6d",x=-35.8,y=#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void PTbac2(int a, int b, int c);

void main()
{
	int t = 0,a = 0, b = 0, c = 0;
	printf("Nhap vao he so:\n");
	t = scanf("%d%d%d", &a,&b,&c);
	PTbac2(a, b, c);
}

void PTbac2(int a, int b, int c)
{
	float x = 0, x1 = 0, x2 = 0, x3 = 0;
	float d = 0;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				printf("\nPhuong trinh co vo so nghiem!!!\n");
			else
				printf("\nPhuong trinh vo nghiem!!!\n");
		}
		else
		{
			printf("\nPhuong trinh co 1 nghiem: %0.1d\n", -c / b);
		}
	}
	else
	{
		d = (b * b) - 4 * a * c;
		if (d < 0)
		{
			printf("\nPhuong trinh vo nghiem!!!!\n");
		}
		else if (d == 0)
		{
			x = -b / 2 * a;
			printf("Phuong trinh co 1 nghiem kep: %0.1f", x);
		}
		else
		{
			x1 = (-b + sqrt(d)) / 2 * a;
			x2 = (-b - sqrt(d)) / 2 * a;
			printf("\nPhuong trinh co 2 nghiem phan biet!!!\n");
			printf("Nghiem x1 la: %0.1f\n", x1);
			printf("Nghiem x2 la: %0.1f\n", x2);
		}
	}
}
	48.6);
}