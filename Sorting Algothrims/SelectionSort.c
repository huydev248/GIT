#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

void swap(int* a, int* b);
void SelectionSort(int a[], int n);
void printArray(int a[], int n);

int main() {
	int a[] = { 5, 2, 4, 1, 3, 7 };
	int array_size = sizeof(a) / sizeof(a[0]);
	printf("Mang a ban dau\r\n", array_size);
	printArray(a, array_size);
	printf("Mang a sau khi su dung Selection Sort: \r\n");
	SelectionSort(a, array_size);
	printArray(a, array_size);
	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int a[], int n) {
	int iMin, i, j;
	for (i = 0; i < n - 1; i++) {
		iMin = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[iMin]) {
				iMin = j;
			}
		}
		swap(&a[i], &a[iMin]);
	}
}

void printArray(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\r\n");
}



