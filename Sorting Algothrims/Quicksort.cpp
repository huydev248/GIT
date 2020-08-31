#include<iostream>
#define MAX 100

using namespace std;

void swap(int* a, int* b);
int Partition(int A[], int start, int end);
void Quicksort(int A[], int start, int end);
void printArray(int A[], int size);

int main()
{
	int i;
	int E[] = { 2,7,4,1,5,3 };
	int arr_size = sizeof(E) / sizeof(E[0]);
	cout << "Given array is: ";
	printArray(E, arr_size);
	cout << "Quick sort: ";
	Quicksort(E, 0, 5);
	for (i = 0; i < 6; i++)
	{
		cout << E[i] << " ";
	}
	return 0;
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\r\n";
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int PartitionIndex = start;
	int i;
	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			swap(&A[i], &A[PartitionIndex]);
			PartitionIndex++;
		}
	}
	swap(&A[PartitionIndex], &A[end]);
	return PartitionIndex;
}

void Quicksort(int A[], int start, int end)
{
	if (start < end)
	{
		int pIndex = Partition(A, start, end);
		Quicksort(A, start, pIndex - 1);
		Quicksort(A, pIndex + 1, end);
	}
}