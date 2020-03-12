#include<stdio.h>

void main()
{
	int a, c, t;
	float b, d;
	a = 123; c = -4685; t = 12;
	b = -45.855; d = 123.425;
	printf("\n \'Chuc cac ban may man\'\n");
	printf("\n \"Chuc cac ban may man\"\n");
	printf("\n \\Chuc cac ban may man\\\n");
	printf("\n \"Tong san luong hang nam tang %2d% \"", t);

	printf("\n\n %d %f %d %f", a, b, c, d);

	printf("\n\n %6d %8.2f %7d %8.2f", a, b, c, d);

	printf("\n\n a = %d, b = %0.2f, c = %d, d = %.2f", a, b, c, d);
}

