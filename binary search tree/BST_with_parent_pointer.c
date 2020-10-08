// no duplicate entries

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
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
	temp->left = temp->right = temp->parent = NULL;
	return temp;
}

void insert(struct node** node, int key)
{
	if(*node == NULL)
		*node = newnode(key);
	else
	{
		int flag = 0;
		struct node* temp = *node;
		while(flag == 0)
		{
			if(key < temp->key)
			{
				if(temp->left)
					temp = temp->left;
				else
				{
					temp->left = newnode(key);
					temp->left->parent = temp;
					flag = 1;
				}
			}
			else if(key > temp->key)
			{
				if(temp->right)
					temp = temp->right
				else
				{
					temp->right = newnode(key);
					temp->right->parent = temp;
					flag = 1;
				}
			}
			else
				flag = 1;
		}
	}
}

void deleteNode(struct node** root, struct node* node)
{
	if(node->left != NULL && node->right != NULL)
	{
		struct temp = node->left;
		while(temp->right)
			temp = temp->right;
		node = temp;
	}
	struct node* p = node->parent;
	struct node* child;
	if(node->left)
		child = node->left;
	else
		child = node->right;

	if(node == *root)
		*root = child;
	if(child)
		child->parent = p;
	if(p)
	{
		if(p->left == node)
			p->left = child;
		else
			p->right = child;
	}
	free(node);
}

void delete(struct node** root, int x)
{
	struct node* node = *root;
	while(node)
	{
		if(x == node->key)
			deleteNode(root, node);
		else if(x < node->key)
			node = node->left;
		else
			node = node->right;
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
		if(node->left)
			node->left->parent = node;
		if(node->right)
			node->right->parent = node;
	}
	return node;
}

struct node* predecesor(struct node* node)
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
		while(node->parent)
		{
			if(node->parent->right == node)
				return node->parent;
			else
				node = node->parent;
		}
		return node->parent;
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