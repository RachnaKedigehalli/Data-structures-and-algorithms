#include<stdio.h>
void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
}
int main()
{
	int n;
	int a[n];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	bubble(a, n);
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}
