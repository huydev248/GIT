#include<stdio.h>

//int DoDai(char* s);

int main()
{
	//char* msg = "hello";
	///*char msg[] = "hello";
	//char* pc = msg;*/
	//int length = 0;
	//length = DoDai(msg);
	//printf("Do dai chuoi la: %d", length);
	//return 0;
	int x = 10;
	int* px = x;
	printf("Gia tri cua x: %d", *px);
	printf("Dia chi cua px: %d", px);
	printf("Dia chi cua x: %d", &x);
	return 0;
}

//int DoDai(char* s)
//{
//	/*int t = 9999;*/
//	int count = 0;
//	for (int i = 0; *(s + i) != 0; i++)
//	{
//		/*if (*(s + i) == 0)
//		{
//			break;
//		}*/
//		count++;
//	}
//	return count;
//}