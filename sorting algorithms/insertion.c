#include<stdio.h>

void insertion(int a[], int n)
{
	int i, j, temp;
	for(int i=1; i<n; i++)
	{
		temp = a[i];
		j = i-1;
		while((j>=0)&&(temp<a[j]))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

int main()
{
	int a[100];
	for(int i=0; i<4; i++)
	{
		scanf("%d", &a[i]);
	}
	insertion(a, 5);
	for(int i=0; i<4; i++)
		printf("%d ", a[i]);
}
