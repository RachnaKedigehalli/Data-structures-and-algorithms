#include<stdio.h>

void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection(int a[], int n)
{
	int i,j,m;
	for(i=0; i<n-1; i++)
	{
		m=0;
		for(j=1; j<n-1-i; j++)
		{
			if(a[j]> a[m])
				m=j;
		}
		if(a[m]>a[j])
			swap(&a[m], &a[j]);
	}
}

int main()
{
	int a[100];
	for(int i=0; i<4; i++)
	{
		scanf("%d", &a[i]);
	}
	selection(a, 5);
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
}
