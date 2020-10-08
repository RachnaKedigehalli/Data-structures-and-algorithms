#include<stdio.h>
#include<stdlib.h>
void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int i, int j, int pivot)
{
	int l, r, k;
	l = i+1;
	r = j;
	while(l<=r)
	{
		while ((l<=r) && (a[l]<=pivot))
			l++;
		while((l<=r)&&(a[r])>pivot)
			r--;
		if(l<=r)
		{
			swap(&a[l], &a[r]);
			l++;
			r--;
		}
	}
	k = l-1;
	swap(&a[i], &a[k]);
	return k;
}
void rqs(int a[], int i, int j)
{	if(i<j)
	{
		int p = rand() % (j-i+1);
		swap(&a[i], &a[i+p]);
		int k = partition(a, i, j, a[i]);
		rqs(a, i, k-1);
		rqs(a, k+1, j);
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
	rqs(a, 0, n-1);
	for(int i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}
