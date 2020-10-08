/*
Data structure which supports the following operations efficiently:
--Add an integer x
--Delete integer with maximum frequency. If there are more than one elements with max freq, delete all
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100
	
struct hash_node{  //doubly linked list
	long long int x;
	long long int count;
	long long int heap_index;
	struct hash_node* next;
	struct hash_node* prev;
};

struct heap_node{
	long long int count;
	struct hash_node* ptr;
};

struct values{
    long long int m;
	long long int p;
	long long int a;
	long long int b;
};

long long int hash_func(long long int x, struct values values)
{
	long long int m = values.m;
	long long int p = values.p;
	long long int a = values.a;
	long long int b = values.b;
	return ((a*x + b) %p) %m;
}

void swap(struct heap_node H[], long long int i, long long int j)
{
	struct heap_node temp = H[i];
	H[i] = H[j];
	H[j] = temp;
	H[i].ptr->heap_index = i;
	H[j].ptr->heap_index = j;
}

void topdown(struct heap_node H[], long long int n, long long int i)  
{
	int l;
	while(2*i+2<n)
	{
		if(H[2*i+1].count > H[2*i+2].count)
			l=2*i+1;
		else
			l=2*i+2;
		if(H[i].count < H[l].count)
		{
			swap(H, i, l);
			i=l;
		}
		else
			break;
	}
	if((2*i+1<n) && (H[i].count < H[2*i+1].count))
	{
		swap(H, i, 2*i+1);
	}
}

void bottomup(struct heap_node H[], long long int i) 
{
	int p;
	p = (i-1)/2;
	while((p>=0) && (H[p].count < H[i].count))
	{
		swap(H, p, i);
		i=p;
		p=(i-1)/2;
	}
}
void add_heap(struct heap_node H[], long long int* n, struct hash_node* node)  
{
	H[*n].count = 1;
	H[*n].ptr = node;
	(*n)++;
	bottomup(H, (*n)-1);
}

void add(struct hash_node* hash_table[], struct heap_node heap[], long long int* n, long long int x, struct values values)
{
	long long int hash = hash_func(x, values);
	struct hash_node* temp = hash_table[hash];
	struct hash_node* flag = hash_table[hash];
	while(temp!=NULL)
	{
		if(temp->next == NULL)
		{
			flag = temp;
		}
		if(x == temp->x)
		{
			temp->count +=1;
			heap[temp->heap_index].count +=1;
			bottomup(heap, temp->heap_index);
			return;
		}
		temp = temp->next;
	}
	if(flag == NULL)
	{
		hash_table[hash] = (struct hash_node*)malloc(sizeof(struct hash_node));
		hash_table[hash]->prev = NULL;
		temp = hash_table[hash];
	}
	else
	{
		flag->next = (struct hash_node*)malloc(sizeof(struct hash_node));
		flag->next = temp;
		temp->prev = flag;
	}
	temp->x = x;
	temp->count = 1;
	temp->heap_index = *n;
	add_heap(heap, n, temp);
	temp->next = NULL;
}

void delete_node(struct hash_node* hash_table[], struct hash_node* node, struct values values)
{
    long long int x = node->x;
    long long int hash = hash_func(x, values);
    if(node->prev)
	    node->prev->next = node->next;
	else
	    hash_table[hash] = node->next;
	if(node->next)
	    node->next->prev = node->prev;
	free(node);
}

void deletemax(struct hash_node* hash_table[], struct heap_node H[], long long int* n, struct values values) 
{
	struct heap_node max = H[0];
	delete_node(hash_table, max.ptr, values);
	H[0]=H[(*n)-1];
	(*n)--;
	topdown(H, *n, 0);
}

void delete_maxfreq(struct hash_node* hash_table[], struct heap_node heap[], long long int* n, struct values values)
{
	if(*n>0)
	{
		long long int max_freq = heap[0].count;
		while((heap[0].count == max_freq)&&(*n>0))
		{
			deletemax(hash_table, heap, n, values);
		}
	}
}

void print_table(struct hash_node* hash_table[], long long int n, struct heap_node heap[])
{
	long long int q=0;
	for(long long int i=0; i<2*N; i++)
	{
		struct hash_node* temp = hash_table[i];
		while(temp!=NULL)
		{
			long long int k = heap[temp->heap_index].count;
			for(long long int j=0; j<k; j++)
			{
				printf("%lld ", temp->x);
				q++;
			}
			temp = temp->next;
		}
	}
	printf("\n");
}

void print_heap(struct heap_node heap[], long long int n)
{
	for(long long int i=0; i<n; i++)
	{
		struct hash_node* ptr = heap[i].ptr;
		for(long long int j=0; j<heap[i].count; j++)
		{
			printf("%lld ", ptr->x);
		}
	}
	printf("\n");
}

int main()
{
    struct values values;
    values.m = 2*N;
	values.p = rand()%values.m + values.m;
	values.a = rand()%values.p;
	values.b = rand()%values.p;
	
	struct hash_node* hash_table[2*N];
	for(long long int j=0; j<2*N; j++)
	{
		hash_table[j] = NULL;
	}
	
	struct heap_node* heap;
	heap = (struct heap_node*)malloc(N * sizeof(struct heap_node));
	for(long long int j=0; j<N; j++)
	{
		heap[j].count = 0;
	}
	
	long long int n = 0;
	long long int num_op;
	printf("Enter the number of operations\n");
	scanf("%lld", &num_op);
	printf("To add element x, input 0 x\nTo delete integer with maximum frequency, input 1\n");
	
	for(long long int i=0; i<num_op; i++)
	{
		int op_no;
		scanf("%d", &op_no);
		if(op_no == 0)
		{
			long long int element;
			scanf("%lld", &element);
			add(hash_table, heap, &n, element, values);
			/*
			printf("Hash table after adding: \n");
			print_table(hash_table, n, heap);
			printf("Heap after adding: \n");
			print_heap(heap, n);
			*/
		}
		else if(op_no == 1)
		{
			delete_maxfreq(hash_table, heap, &n, values);
			/*
			printf("Hash table after deleting: \n");
			print_table(hash_table, n, heap);
			printf("Heap after deleting: \n");
			print_heap(heap, n);
			*/
		}
	}
}
