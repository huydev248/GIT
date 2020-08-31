#include<stdio.h>
#include<stdbool.h>

int top = -1;


bool IsFull(int capacity)
{
	if (top >= capacity - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Push(int stack[], int value, int capacity)
{
	if (IsFull(capacity) == true)
	{
		printf("Stack is Full!\r\n");
	}
	else
	{
		++top;
		stack[top] = value;
	}
}

void Pop()
{
	if (IsEmpty() == true)
	{
		printf("Stack is Empty!\r\n");
	}
	else
	{
		--top;
	}
}

int Top(int stack[])
{
	return stack[top];
}

int Size()
{
	return top + 1;
}

int main()
{
	int top = -1;
	int capacity = 3;
	int stack[3];

	Push(stack, 1, capacity);
	printf("Size of stack is %d\r\n", Size());

	Push(stack, 2, capacity);
	Push(stack, 3, capacity);
	printf("Size of stack is %d\r\n", Size());

	Push(stack, 4, capacity); //Stack is full


	printf("Element at the top of the stack is %d\r\n", Top(stack));

	for (int i = 0; i < 3; i++)
	{
		Pop();
	}
	printf("Size of stack now is %d\r\n", Size()); 

	Pop();//Stack is empty
	return 0;
}