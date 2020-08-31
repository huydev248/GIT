#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

void Free(Node* root) {
	if (root == NULL) {
		return;
	}
	Free(root->left);
	Free(root->right);
	free(root);
}

int LeftOf(const Node* root, const int value) {
	return value < root->data;
}

int RightOf(const Node* root, const int value) {
	return value > root->data;
}

Node* Insert(Node* root, const int value) {
	if (root == NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->left = NULL;
		node->right = NULL;
		node->data = value;
		return node;
	}
	if (LeftOf(root, value)) {
		root->left = Insert(root->left, value);
	}
	else if (RightOf(root, value)) {
		root->right = Insert(root->right, value);
	}
	return root;
}

bool Search(Node* root, int value) {
	if (root == NULL) {
		return false;
	}
	if (root->data == value) {
		return true;
	}
	else if (LeftOf(root->left, value)) {
		return Search(root->left, value);
	}
	else if (RightOf(root->right, value)) {
		return Search(root->right, value);
	}
}

int LeftMostValue(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

Node* Delete(Node* root, int value) {
	if (root == NULL) {
		return root;
	}
	if (LeftOf(root, value)) {
		root->left = Delete(root->left, value);
	}
	else if (RightOf(root, value)) {
		root->right = Delete(root->right, value);
	}
	else {
		if (root->left == NULL) {
			Node* newRoot = root->right;
			free(root);
			return newRoot;
		}
		if (root->right == NULL) {
			Node* newRoot = root->left;
			free(root);
			return newRoot;
		}
		root->data = LeftMostValue(root->right);
		root->right = Delete(root->right, root->data);
	}
	return root;
}

void PreOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(Node* root) {
	if (root != NULL) {
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(Node* root) {
	if (root != NULL) {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

int FindMin(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty\r\n");
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	return FindMin(root->left);
}

int FindMax(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty\r\n");
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	return FindMax(root->right);
}

int FindHeight(Node* root) {
	if (root == NULL) {
		return -1;
	}
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int main() {
	Node* root = NULL;

	root = Insert(root, 25);
	root = Insert(root, 15);
	root = Insert(root, 50);
	root = Insert(root, 10);
	root = Insert(root, 22);

	printf("Duyet PreOrder: \r\n");
	PreOrder(root);
	printf("\nDuyet InOrder: \r\n");
	InOrder(root);
	printf("\nDuyet PostOrder: \r\n");
	PostOrder(root);

	printf("\n\n=== Them phan tu 12 vao BST === \r\n");
	root = Insert(root, 12);
	printf("\nDuyet PreOrder: \r\n");
	PreOrder(root);
	printf("\nDuyet InOrder: \r\n");
	InOrder(root);
	printf("\nDuyet PostOrder: \r\n");
	PostOrder(root);

	printf("\n\n=== Xoa phan tu 50 khoi BST ===\r\n");
	root = Delete(root, 50);
	printf("\nDuyet PreOrder: \r\n");
	PreOrder(root);
	printf("\nDuyet InOrder: \r\n");
	InOrder(root);
	printf("\nDuyet PostOrder: \r\n");
	PostOrder(root);

	Free(root);
	root = NULL;
	return 0;
}