#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node* search(struct node* node, int key)
{
	while(node != NULL)
	{
		if(x == node->key)
			return node;
		else if(x < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

struct node* newnode(int key)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// root = insert(root, key)
struct node* insert(struct node* node, int key)
{
	if(node == NULL)
		return newnode(key);
	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	return node;
}

struct node* delete(struct node* node, int x)
{
	if(node == NULL)
		return node;
	if(x < node->key)
	{
		node->left = delete(node->left, x);
		return node;
	}
	else if(x > node->key)
	{
		node->right = delete(node->right, x);
		return node;
	}
	if(node->left != NULL && node->right != NULL)
	{
		struct node* temp = node->left;
		while(temp->right)
			temp = temp->right;
		node->key = temp->key;
		node->left = delete(node->left, temp->key);   // check....return node
	}
	else
	{
		if(node->left)
			child = node->left;
		else
			child = node->right;
		free(node);
		return child;
	}
}

struct node* build(int* A, int l, int r)
{
	struct node* node = NULL;
	if(l <= r)
	{
		int m = (l+r)/2;
		node = (struct node*)malloc(sizeof(struct node));
		node->key = A[m];
		node->left = build(A, l, m-1);
		node->right = build(A, m+1, r);
	}
	return node;
}

struct node* predecesor(struct node* node, struct node* root)
{
	if(node == NULL)
		return node;
	if(node->left)
	{
		node = node->left;
		while(node->right)
			node = node->right;
		return node;
	}
	else
	{
		struct node* predecesor = NULL;
		while(node != root)
		{
			if(node->key < root->key)
				root = root->left;
			else
			{
				predecesor = root;
				root = root->right;
			}
		}
		return predecesor;
	}
}

// least common ancestor
struct node* LCA(struct node* node, struct node* L, struct node* R)
{
	if(node == NULL || L->key > R->key)
		return NULL;
	if(R->key < node->key)
		return LCA(node->left, L, R);
	if(L->key > node->key)
		return LCA(node->right, L, R);
	return node;
}
