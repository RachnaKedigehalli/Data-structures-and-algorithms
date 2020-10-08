#include<stdio.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node* next;
};

bool cycle(struct node* head)
{
	struct node* p1=head;
	struct node* p2=head;
	while(p2!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
		if(p2!=NULL)
			p2=p2->next;
		else 
			return false;
		if(p1==p2)
			return true;
	}
	return false;
}
