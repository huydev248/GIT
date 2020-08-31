#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define MAX 100

bool isEmpty(int rear, int front) {
	if (rear == -1 && front == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool isFull(int arraySize, int rear) {
	return (rear == arraySize);
}

int Front(int queue[], int front) {
	return queue[front];
}

int arraySize(int rear, int front) {
	return (rear - front);
}

void Enqueue(int a[], int element, int* rear, int* front, int arraySize) {
	if (isFull(arraySize, *rear) == true) {
		return;
	}
	else if (isEmpty(*rear, *front) == true) {
		*front = *rear = 0;
	}
	else {
		*rear = *rear + 1;
	}
	a[*rear] = element;
}

void Dequeue(int a[], int* front, int* rear) {
	if (isEmpty(*rear, *front) == true) {
		return;
	}
	else if (*front == *rear) {
		*front = *rear = -1;
	}
	else {
		(*front)++;
	}
}


int main() {
	int queue[MAX];
	int front = -1;
	int rear = -1;
	int N;
	printf("Nhap so luong phan tu trong Queue: \r\n");
	scanf("%d", &N);

	//Adding element
	for (int i = 0; i < N; i++) {
		Enqueue(queue, i+1, &rear, &front, N);
	}
	
	printf("Liet ke Queue: \r\n");
	for (int i = front; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\r\n");

	printf("Phan tu o dau Queue: \r\n");
	int final = Front(queue, front);
	printf("%d\r\n", final);
	return 0;
}