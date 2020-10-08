#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node* next;
};

bool search(struct node* head, int x)
{
	while(head!=NULL)
	{
		if(head->data==x)
			return true;
		head=head->next;
	}
	return false;
}

void add_at_beg(struct node** head, int key)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = key;
	temp->next = *head;
	*head = temp;
}

void add_at_end(struct node* head, int key)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = key;
	temp->next = NULL;
	struct node* ptr = head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next = temp;
}

void delete_at_beg(struct node**head)
{
	struct node* temp;
	if(head!=NULL)
	{
		temp=*head;
		*head=temp->next;
		free(temp);
	}
}

void delete_at_end(struct node* head)
{
	struct node* temp;
	struct node* end;
	temp = head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	end=temp->next;
	temp->next=NULL;
	free(end);
}

void reverse(struct node** head)
{
	struct node* prev;
	struct node* curr;
	struct node* nex;
	prev=NULL;
	curr=*head;
	while(curr!=NULL)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;
	}
	*head=prev;
}

void print(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d->", temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
 
int main(void)
{
	struct node* head=malloc(sizeof(struct node));
	head->data=5;
	head->next=NULL;
	struct node** ptr = &head;
	add_at_beg(ptr, 4);
	add_at_end(head, 7);
	add_at_beg(ptr, 6);
	add_at_end(head, 0);
	reverse(ptr);
	delete_at_beg(ptr);
	print(head);
	delete_at_end(head);
	print(head);
}
