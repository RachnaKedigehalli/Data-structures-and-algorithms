//Given a binary string (having alpha numeric values) of length 100,000 and an integer k, implement an efficient algorithm to compute the  length of the largest sub-string which  repeats at least k times.


//checks if there exists a sting of length l that repeats k times.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int index;
	int count;
	struct node* next;
};
int insert(char* string, int length, int k, struct node* H[], int hash, int index);
int compare(char* string,int length, int i, int j);

void print(struct node* H[], int p)
{
	for(int i=0; i<p; i++)
	{
		struct node* temp=H[i];
		while(temp!=NULL)
		{
			printf("%d (%d)->", temp->index, temp->count);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

int check(char* string, int length, int k)
{
	int n = strlen(string);
	int p = 2*n;
	struct node* H[p];
	for(int j=0; j<p; j++)
	{
		H[j] = NULL;
	}
	
	int hash = string[0] - 48;
	int powerof2 = 2;
	for(int i=1; i<length; i++)
	{
		hash = (2*hash + string[i] - 48)%p;
		powerof2 = powerof2 * 2;  
	}
	if(insert(string, length, k, H, hash, 0)==1)
	{
		return 1;
	}
	for(int i=1; i<=n-length; i++)
	{
		hash = (2*hash + string[i+length-1] - 48 - powerof2*(string[i-1] - 48))%p;
		if(hash<0)
			hash = hash+p;
		if(insert(string, length, k, H, hash, i)==1)
		{
			return 1;
		}
	}
	for(int j=0; j<p; j++)
	{
		free(H[j]);
	}
	return 0;
}

int insert(char* string, int length, int k, struct node* H[], int hash, int index)
{
	if(H[hash] == NULL)
	{
		H[hash] = (struct node*)malloc(sizeof(struct node));
		H[hash]->index = index;
		H[hash]->count = 1;
		H[hash]->next = NULL;
		if(H[hash]->count == k)
			return 1;
	}
	else
	{
		struct node* temp = H[hash];
		struct node* flag = temp;
		while(temp!=NULL)
		{
			if(temp->next == NULL)
			{
				flag = temp;
			}
			if(compare(string, length, temp->index, index)==1)
			{
				temp->count +=1;
				if(temp->count == k)
					return 1;
				return 0;
			}
			temp = temp->next;
		}
		flag->next = (struct node*)malloc(sizeof(struct node));
		flag = flag->next;
		flag->index = index;
		flag->count = 1;
		flag->next = NULL;	
	}
	return 0;
}

int compare(char* string,int length, int i, int j)
{
	int m;
	for(m=0; m<length; m++)
	{
		if(string[i+m]!=string[j+m])
			break;
	}
	if(m==length)
		return 1;
	else
		return 0;
}

int BS(char* string, int i, int j, int k, int* length)
{
	if(i<=j)
	{
		int l=(i+j)/2;
		if(check(string, l, k)==1)
		{
			if(l>*length)
				*length = l;
			BS(string, l+1, j, k, length);
		}
		else
		{
			BS(string, i, l-1, k, length);
		}
	}
}

int main()
{
	char* string;
	int k;
	scanf("%s", string);
	scanf("%d", &k);
	int n = strlen(string);
	int length=0;
	BS(string, 1, n-k+1, k, &length);
	printf("Answer:%d\n", length);
}
