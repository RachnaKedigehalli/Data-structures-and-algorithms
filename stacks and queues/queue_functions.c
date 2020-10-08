#include<stdio.h>
void enqueue(int Q[], int tail, int x)
{
	tail++;
	Q[tail]=x;
}
int dequeue(int Q[], int head)
{
	head++;
	return Q[head-1];
}

