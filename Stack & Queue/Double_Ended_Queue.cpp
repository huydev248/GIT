#include<iostream>
#include<stdbool.h>
#include<cstdio>

//Double-ended queue

//Insert & Delete at the back
void InsertAtBack(int queue[],int& rear,int& front,int element, int arraySize)
{
	if(rear == arraySize)
	{
		printf("Queue is full\r\n");
	}
	else
	{
		queue[rear]= element;
		rear = rear + 1;
	}
}

void DeleteAtBack(int queue[], int& rear, int front)
{
	if(rear == front)
	{
		printf("Queue is empty");
	}
	else
	{
		rear = rear - 1;
		queue[rear] = 0;
	}
}


//Insert & Delete at the front
void InsertAtFront(int queue[], int& rear, int& front, int element, int arraySize)
{
	if(rear == arraySize)
	{
		printf("Queue is full\r\n");
	}
	else
	{
		for(int i = rear; i > front; i--)
		{
			queue[i] = queue[i-1];
		}
		queue[front] = element;
		rear = rear + 1;
	}
}

void DeleteAtFront(int queue[], int& front, int& rear)
{
	if(rear == front)
	{
		printf("Queue is empty\r\n);
	}
	else
	{
		queue[front] = 0;
		front = front + 1;
	}
}

int GetFront(int queue[], int front)
{
    return queue[front];
}

int GetRear(int queue[], int rear)
{
    return queue[rear-1];
}