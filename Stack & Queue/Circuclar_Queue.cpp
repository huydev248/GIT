#include<iostream>
#include<stdbool.h>

using namespace std;

void Enqueue(int queue[], int& rear, int& count, int arraySize, int element)
{
	if(count == arraySize)
	{
		printf("Queue is full\r\n");
	}
	else
	{
		queue[rear] = element;
		rear = (rear + 1) % arraySize;
		count++;
	}
}

void Dequeue(int queue[], int& front, int& count)
{
	if(count == 0)
	{
		printf("Queue is empyty\r\n");
	}
	else
	{
		queue[front] = 0;
		front--;
		count--;
	}
}

int Front(int queue[], int front)
{
	return queue[front];
}

int arraySize(int count)
{
	return count;
}

bool IsEmpty(int count)
{
	return (count == 0);
}
