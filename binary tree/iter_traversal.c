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

void preorder(struct node* root, struct node* S[])
{
	if(root!=NULL)
	{
		int top=-1;
		top++;
		S[top] = root;
		while(top>=0)
		{
			visit(S[top]);
			root=S[top];
			top--;
			if(root->right!=NULL)
			{
				top++;
				S[top]=root->right;
			}
			if(root->left!=NULL)
			{
				top++;
				S[top]=root->left;
				
			}
		}
	}
}

void inorder(struct node* root, struct node* S[], int B[])
{
	if(root!=NULL)
	{
		int top=-1;
		top++;
		S[top]=root; B[top]=0;
		while(top>=0)
		{
			if(B[top]==0)
			{
				root=S[top];
				top--;
				if(root->right!=NULL)
				{
					top++;
					S[top]=root->right;
					B[top]=0;
				}
				top++;
				S[top]=root;
				B[top]=1;
				if(root->left!=NULL)
				{
					top++;
					S[top]=root->left;
					B[top]=0;
				}
			}
			else
			{
				visit(S[top]);
				top--;
			}
		}
	}
}

void levelorder(struct node* root, struct node* Q[])
{
	int head=0;
	int tail=-1;
	tail++;
	Q[tail]=root;
	while(tail>=head)
	{
		root=Q[head];
		visit(root);
		head++;
		if(root->left!=NULL)
		{
			tail++; Q[tail]=root->left;
		}
		if(root->right!=NULL)
		{
			tail++; Q[tail]=root->right;
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char arr[n];
	struct node* S[2*n];
	int B[2*n];
	struct node* Q[n];
	scanf("%s", arr);
	struct node* root = build(arr, root, 0, n);
	preorder(root, S);
	printf("\n");
	inorder(root, S, B);
	printf("\n");
	levelorder(root, Q);
}
