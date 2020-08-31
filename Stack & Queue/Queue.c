#include<stdio.h>
#include<stdbool.h>

void Enqueue(char queue[], int element, int* rear, int arraySize)
{
	if (*rear == arraySize)
	{
		printf("Queue is full\r\n");
	}
	else
	{
		queue[*rear] = element; //Add element to the back
		(*rear)++;
	}
}

void Dequeue(char queue[], int* front, int rear)
{
	if (*front == rear)
	{
		printf("Queue is empty\r\n");
	}
	else
	{
		queue[*front] = 0; //Delete the front element
		(*front)++;
	}
}

char Front(char queue[], int front) //Return element at front
{
	return queue[front];
}

int arraySize(int rear, int front) //Return size of queue
{
	return (rear - front);
}

bool IsEmpty(int rear, int front) //Check if the queue is empty
{
	return (rear - front);
}

int main()
{
	char queue[20] = { 'a','b','c','d' };
	int front = 0;
	int rear = 4;
	int size = 20;
	int N = 3;
	char ch;

	for (int i = 0; i < N; i++)
	{
		ch = Front(queue, front);
		Enqueue(queue, ch, &rear, size);
		Dequeue(queue, &front, rear);
	}

	for (int i = front; i < rear; i++)
	{
		printf("%c ", queue[i]);
	}
	printf("\n");
	return 0;
}