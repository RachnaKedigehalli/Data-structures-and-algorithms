#include<stdio.h>

void push(int S[], int top, int x)
{
	top++;
	S[top]=x;
}

int pop(int S[], int top)
{
	top--;
	return S[top+1];
}


