#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node* left;
	struct node* right;
	struct node* parent;
};
void tree(char arr[], struct node* root, int i, int n);
struct node* newnode(char data, struct node* parent)
{
	struct node* temp= (struct node*) malloc(sizeof(struct node));
	temp->data=data;
	temp->parent=parent;
	temp->left= NULL;
	temp->right=NULL;
	return temp;
}

void build(struct node* root, char* ptr, int i, int k)//ptr is current node, k is 2 power of level, i
{
	if(*ptr!='\0')
	{
		if(*(ptr+i+k)!='\0')
		{
			struct node* l = newnode(*(ptr+i+k), root);
			root->left = l;
			k*=2;//i+=1;
			build(l, ptr+k, i, k);
		}
		k/=2;//i-=1;
		if(*(ptr+i+k+1)!='\0')
		{
			struct node* r = newnode(*(ptr+i+k+1), root);
			root->right= r;
			k*=2;i+=1;
			build(r, ptr+k+1, i, k);
		}
	}
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

void inorder(struct node* node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}

void postorder(struct node* node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}

int main()
{
	struct node* root = (struct node*) malloc(sizeof(struct node));
	root->parent=NULL;
	root->left=NULL;
	root->right=NULL;
	int n;
	scanf("%d", &n);
	char arr[n];
	scanf("%s", arr);

	tree(arr, root, 0, n);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}

void tree(char arr[], struct node* root, int i, int n)
{
	if(i<n)
	{
		if(root->parent==NULL)
		{
			root->data = arr[i];
		}
		struct node* l = newnode(arr[2*i+1], root);
		struct node* r = newnode(arr[2*i+2], root);
		root->left=l;
		root->right=r;
		tree(arr, l, 2*i+1, n);
		tree(arr, r, 2*i+2, n);
	}
}
