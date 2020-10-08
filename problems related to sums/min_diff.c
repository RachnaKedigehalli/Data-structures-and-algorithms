//min(|ai-aj|)i!=j
#include<stdio.h>
#include<math.h>
int imp1(int n, int arr[]);
int imp2(int n, int arr[]);
void msort(int a[], int i, int j);
int main(void)
{
	int n, y;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	y = imp2(n, arr);
	printf("%d", y);
}

int imp1(int n, int arr[])
{
	int min=123243435;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(fabs(arr[i]-arr[j])<min)
				min=fabs(arr[i]-arr[j]);
		}
	}
	return min;
}

int imp2(int n, int arr[])
{
	msort(arr, 0, n-1);
	int min=2235676765;
	for(int i=1; i<n; i++)
	{
		if(fabs(arr[i]-arr[i-1])<min)
			min=fabs(arr[i]-arr[i-1]);
	}
	return min;
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
