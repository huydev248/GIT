#include <stdio.h>
#include <math.h>
#include "GiaiPTbac2.h"

void main()
{
	int t = 0; 
	int a = 0, b = 0, c = 0;

	printf("Nhap cac he so phuong trinh bac 2:\n", a, b, c);
	t = scanf("%d%d%d", &a,&b,&c);

	PTbac2(a, b, c);
}
