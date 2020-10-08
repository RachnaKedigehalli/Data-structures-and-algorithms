#include<stdio.h>
void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merge(int a[], int i, int k, int j)
{
	int l, r, p;
	int b[j-i+1];
	l=i; r=k+1; p =0;
	while((l<=k) && (r<=j))
	{
		if(a[l]<=a[r])
		{
			b[p] = a[l];
			p++;
			l++;
		}
		else
		{
			b[p] = a[r];
			p++;
			r++;
		}
	}
	while(l<=k)
	{
		b[p] = a[l];
		p++;
		l++;
	}
	while(r<=j)
	{
		b[p] = a[r];
		p++;
		r++;
	}
	p=0;
	while(i<=j)
	{
		a[i] = b[p];
		i++;
		p++;
	}
}
void msort(int a[], int i, int j)
{
	int k;
	if(i<j)
	{
		k = (i+j)/2;
		msort(a, i, k);
		msort(a, k+1, j);
		merge(a, i, k, j);
	}
}
int main()
{
	int a[100];
	for(int i=0; i<4; i++)
	{
		scanf("%d", &a[i]);
	}
	msort(a, 0, 3);
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
}
