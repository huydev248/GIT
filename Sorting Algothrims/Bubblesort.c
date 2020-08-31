#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)break;
	}
}

void printArray(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\r\n");
}

int main() {
	int a[] = { 5, 2, 4, 1, 3, 7 };
	int array_size = sizeof(a) / sizeof(a[0]);
	printf("Mang a ban dau: \r\n");
	printArray(a, array_size);
	printf("Mang a sau khi su dung Bubble Sort: \r\n");
	BubbleSort(a, array_size);
	printArray(a, array_size);
	return 0;
}





