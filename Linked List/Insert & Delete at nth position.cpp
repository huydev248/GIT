#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head; //Node* head = NULL (same meaning)
typedef struct node Node;

Node* DeleteWithReturnValue(Node* head, int n);
void DeleteWithoutReturnValue(int n);
Node* InsertWithReturnValue(Node* head, int data, int pos);
void InsertWithoutReturnValue(int data, int x);
void InsertAtTheEnd(int data);
struct node* AddNode(int value);
void Print();

int main()
{
	//Insert Node
	head = NULL;
	InsertWithoutReturnValue(2, 1);
	InsertWithoutReturnValue(3, 2);
	InsertWithoutReturnValue(4, 1);
	InsertWithoutReturnValue(5, 2);
	Print();

	head = NULL;
	head = InsertWithReturnValue(head, 2, 1);
	head = InsertWithReturnValue(head, 3, 2);
	head = InsertWithReturnValue(head, 4, 1);
	head = InsertWithReturnValue(head, 5, 2);

	//Delete Node
	head = DeleteWithReturnValue(head, 3); //DeleteWithoutReturnValue(3); (same meaning)

	Print();
	return 0;
}

//Create 1 Node
struct node* AddNode(int value)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}

//Insert 1 Node without return value
void InsertWithoutReturnValue(int data, int x)
{
	struct node* temp = AddNode(data);

	if (x == 1) //Insert at the beginning Linked List
	{
		temp->next = head;
		head = temp;
	}
	else // Insert at nth position, x is the position
	{
		struct node* temp1 = head;
		for (int i = 0; i < x - 2; i++)
		{
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

//Insert 1 Node with return value
Node* InsertWithReturnValue(Node* head, int data, int pos)
{
	Node* temp = AddNode(data);

	if (pos == 1) //Insert at the beginning
	{
		temp->next = head;
		head = temp;
	}
	else // Insert at nth position, pos is the position
	{
		struct node* temp1 = head;
		for (int i = 0; i < pos - 2; i++)
		{
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
	return head;
}

void InsertAtTheEnd(int data)
{
	Node* temp = AddNode(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node* temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}


void Print()
{
	struct node* temp = head;
	while (temp != NULL) //Traversal Linked List
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\r\n");
}

void DeleteWithoutReturnValue(int n)
{
	Node* temp = head;

	if (head == NULL)return;

	if (n == 1)
	{
		head = temp->next;
		free(temp); //Delele at the beginning Linked List
	}
	else
	{
		for (int i = 0; i < n - 2; i++)
		{
			temp = temp->next; //Delele at nth position Linked List
		}
		Node* temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
}

Node* DeleteWithReturnValue(Node* head, int n)
{
	Node* temp = head;

	if (head == NULL)
	{
		return head;
	}

	if (n == 1)
	{
		head = temp->next;
		free(temp); //Delele at the beginning Linked List
	}
	else
	{
		for (int i = 0; i < n - 2; i++)
		{
			temp = temp->next; //Delele at nth position Linked List
		}
		Node* temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
	return head;
}

