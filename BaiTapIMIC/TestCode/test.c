#include <stdio.h>
#include <math.h>

double Power_n(double x, long n);
double qPower_n(double x, long n);

int main()
{
	double x = 0;
	long n = 0;
	printf("Nhap x va n: \r\n", x, n);
	scanf("%f%d", &x, &n);

	Power_n(x, n);
	qPower_n(x, n);
}

double Power_n(double x, long n)
{
	double result = 1;
	while (n--)
	{
		result *= x;
	}
	printf("%f\r\n", result);
	return result;
}

double qPower_n(double x, long n)
{
	double result = 1;
	while (n)
	{
		if (n % 2 == 1)
		{
			result *= x;
		}
		x *= x;
		n /= 2;
	}
	printf("%f\r\n", result);
	return result;
}

