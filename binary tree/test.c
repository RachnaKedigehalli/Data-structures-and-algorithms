#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* newnode(char data, struct node* parent)
{
	struct node* temp= (struct node*) malloc(sizeof(struct node));
	temp->data=data;
	temp->parent=parent;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* build(char arr[], struct node* root, int i, int n)
{
	if(i<n)
	{
		struct node* temp =newnode(arr[i], NULL);
		root = temp;
		root->left = build(arr, root->left, 2*i+1, n);
		root->right = build(arr, root->right, 2*i+2, n);
	}
	return root;
}

void visit(struct node* node)
{
	printf("%c", node->data);
}

void preorder(struct node* node)
{
	if(node!=NULL)
	{
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}

int main(void)
{
	char arr[]={'a','b', 'c', 'd'};
	int n= 4;
	struct node* root = build(arr, root, 0, n);
	preorder(root);
}
