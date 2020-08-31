#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head; 				// Global variable

struct Node* GetNewNode(int data);
void InsertAtTail(int x);
void InsertAtHead(int x);
void Print(struct Node* head);
void ReversePrint(struct Node* head);

int main()
{
	head = NULL;
	InsertAtHead(2); 			// Insert a Node at the beginning
	InsertAtHead(4);
	InsertAtHead(6);
	InsertAtHead(8);
	/*InsertAtTail(3); 			// Insert a Node in Forward
	InsertAtTail(4);
	InsertAtTail(5);*/
	Print(head);        		// Print Doubly Linked List
	printf("\r\n");
	ReversePrint(head);  		// Reverse and Print Doubly Linked List
	return 0;
}

struct Node* GetNewNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtTail(int x)
{
	struct Node* temp = GetNewNode(x);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	struct Node* temp1 = head;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
}

void InsertAtHead(int x)
{
	struct Node* temp = GetNewNode(x);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	struct Node* temp1 = head;
	temp1->prev = temp;
	temp->next = temp1;
	head = temp;
}

void Print(struct Node* head)
{
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void ReversePrint(struct Node* head)
{
	struct Node* temp = head;
	if (temp == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	printf("Reverse: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

