#include<stdio.h>
int binary(int* arr, int l, int r, int x)
{
	int k=(l+r)/2;
	if(l<r)
	{
		if(arr[k]==x)
			return k;
		else if(arr[k]>x)
			return binary(arr, l, k-1, x);
		else
			return binary(arr, k+1, r, x);
	}
	return -1;
}
int main()
{
	int n, x;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	if(binary(arr, 0, n-1, x)>=0)
		printf("%d", binary(arr, 0, n-1, x));
	else
		printf("x is not in arr");
}
