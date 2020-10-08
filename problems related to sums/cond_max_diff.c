//max(aj-ai), j>i
//application:buying and sellling of stocks
#include<stdio.h>
int imp1(int n, int arr[]);
int imp2(int n, int arr[]);
int main(void)
{
	int n, max;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//max=imp1(n, arr);
	max=imp2(n, arr);
	printf("%d", max);
}

int imp1(int n, int arr[])
{
	int max=0;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[j]-arr[i]>max)
				max=arr[j]-arr[i];
		}
	}
	return max;
}

int imp2(int n, int arr[])
{
	int i=0, max=0;
	for(int j=1; j<n; j++)
	{
		if(arr[j]-arr[i]>max)
			max=arr[j]-arr[i];
		if(arr[i]>arr[j])
			i=j;
	}
	return max;
}
