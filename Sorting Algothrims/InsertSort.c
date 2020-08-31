#include<stdio.h>
#define MAX 100

void InsertSort(int a[], int n);
void printArray(int a[], int size);

int main()
{
    int a[] = {2,7,4,1,5,3};
    int arr_size = sizeof(a)/sizeof(a[0]);
    printf("Given array is: ");
    printArray(a,arr_size);
    printf("Insert Sort: ");
    for(int i=0;i<6;i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void InsertSort(int a[], int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int value = a[i];
        int hole = i;
        while(hole>0 && a[hole-1]>value)
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
}

void printArray(int a[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\r\n");
}