#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;
// void Delete(int n);
void Print();
// void Insert(int data, int x);
struct Node* Reverse(struct Node* head);

int main()
{
	head = NULL;
	int i, n, x;
	printf("Enter how many numbers: \r\n");
	scanf("%d", &n);

	// Insert node lien tiep nhau hoac vi tri bat ky
	for (i = 0; i < n; i++)
	{
		printf("Enter numbers: \r\n");
		scanf("%d", &x);
		// Insert(x, i + 1);
	}
	Print(); // In Linked List

	// Reverse Linked List - Iterative method
	head = Reverse(head);
	Print();

	// Delete a node at nth position
	int pos;
	printf("Enter delete position: \r\n");
	scanf("%d", &pos);
	Delete(pos);
	Print();
	return 0;
}

struct Node* Reverse(struct Node* head)
{
	struct Node* next, * prev, * current;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

// void Insert(int data, int x)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	if (x == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	for (int i = 0; i < x - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Print()
{
	struct Node* temp1 = head;
	while (temp1 != NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}

// void Delete(int n)
{
	struct Node* temp3 = head;
	if (n == 1)
	{
		head = temp3->next;
		free(temp3);
		return;
	}

	for (int i = 0; i < n - 2; i++)
	{
		temp3 = temp3->next;
	}
	struct Node* temp4 = temp3->next;
	temp3->next = temp4->next;
	free(temp4);
}










