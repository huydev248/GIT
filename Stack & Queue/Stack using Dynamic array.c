#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<malloc.h>

typedef struct stack
{
	int top;
	unsigned capacity;
	int* array;
}Stack;

Stack* newStack(unsigned capacity)
{
	struct stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int IsFull(Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int IsEmpty(Stack* stack)
{
	return stack->top == -1;
}

void Push(Stack* stack, int value)
{
	if (IsFull(stack))
	{
		return;
	}
	stack->array[++stack->top] = value;
	printf("%d pushed to stack\r\n", value);
}

int Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		return INT_MIN;

	}
	else
	{
		return stack->array[stack->top--];
	}
}

int Peek(Stack* stack)
{
	if (IsEmpty(stack))
	{
		return INT_MIN;
	}
	else
	{
		return stack->array[stack->top];
	}
}

int main()
{
	Stack* stack = newStack(2);

	Push(stack, 14);
	Push(stack, 24);
	Push(stack, 34);

	printf("%d popped from stack\r\n", Pop(stack));

	printf("Top value of the stack is %d\r\n", Peek(stack));

	return 0;
}

