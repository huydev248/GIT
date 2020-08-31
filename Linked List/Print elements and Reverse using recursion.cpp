#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;
struct Node* Insert(struct Node* head, int data);
void Print(struct Node* head);
void ReversePrint(struct Node* head);
void Reverse(struct Node* p);

int main()
{
	head = NULL;
	head = Insert(head, 2); // Insert a Node at the end of Linked List
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head); // Print elements of Linked List in forward by using Recursion
	printf("\r\n");
	ReversePrint(head); // Reverse order Linked List using Recursion (address of head Node did not change)
	printf("\r\n");
	Reverse(head); // Reverse Linked List using Recursion (change address of head Node)
	Print(head);
	return 0;
}

struct Node* Insert(struct Node* head, int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct Node* temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}

void Print(struct Node* head)
{
	if (head == NULL)
	{
		return;
	}
	printf("%d ", head->data);
	Print(head->next);
}

void ReversePrint(struct Node* head)
{
	if (head == NULL)
	{
		return;
	}
	ReversePrint(head->next);
	printf("%d ", head->data);
}

void Reverse(struct Node* p)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	Reverse(p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
}
	


























