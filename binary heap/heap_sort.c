#include<stdio.h>
void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void topdown_max(int* H, int n, int i)  //max
{
	int l;
	while(2*i+2<n)
	{
		if(H[2*i+1]>H[2*i+2])
			l=2*i+1;
		else
			l=2*i+2;
		if(H[i]<H[l])
		{
			swap(&H[i], &H[l]);
			i=l;
		}
		else
			break;
	}
	if((2*i+1<n) && H[i]<H[2*i+1])
	{
		swap(&H[i], &H[2*i+1]);
	}
}

void build_max(int* H, int n)  //max
{
	for(int i=n/2; i>=0; i--)
	{
		topdown_max(H, n, i);
	}
}

int deletemax(int* H, int n)  //max
{
	int max = H[0];
	H[0]=H[n-1];
	n--;
	topdown_max(H, n, 0);
	return max;
}

void heap_sort(int* H, int n)
{
	int d=n;
	build_max(H, n);
	for(int i=0; i<d; i++)
	{
		int max = deletemax(H, n);
		H[n-1]=max;
		n--;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	heap_sort(arr, n);
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
}
