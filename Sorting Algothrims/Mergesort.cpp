#include<iostream>
#define MAX 100

using namespace std;

void printArray(int a[], int size);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);

int main()
{
	int B[] = { 2,7,4,1,5,3 };
	int arr_size = sizeof(B) / sizeof(B[0]);
	printf("Given array is: ");
	printArray(B, arr_size);
	mergeSort(B, 0, arr_size - 1);
	printf("Merge Sort: ");
	printArray(B, arr_size);
	printf("\r\n");
	return 0;
}

void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[MAX];
	int R[MAX];

	for (i = 0; i < n1; i++)
	{
		L[i] = a[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = a[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r)
{
	int m;
	if (l < r)
	{
		m = l + (r - l) / 2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);

		merge(a, l, m, r);
	}
}

void printArray(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\r\n");
}
