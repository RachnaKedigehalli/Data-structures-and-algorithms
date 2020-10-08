//ai+aj=x
#include<stdio.h>
int main(void)
{
	int n, x, y;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	//y = imp1(n, arr, x);
	y = imp2(n, arr, x);
	printf("%d", y);
}

int imp1(int n, int arr[], int x)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(arr[i]+arr[j]==x)
				return 1;
		}
	}
	return 0;
}

int imp2(int n, int arr[], int x)
{
	msort(arr, 0, n-1);
	int l=0;
	int r=n-1;
	while(l<=r)
	{
		if(arr[l]+arr[r]==x)
			return 1;
		else if(arr[l]+arr[r]>x)
			r--;
		else
			l++;
	}
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
