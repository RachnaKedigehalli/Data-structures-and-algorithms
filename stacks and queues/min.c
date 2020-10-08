#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int A[n]; int B[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &A[i]);
	}
	imp1(n, A, B);
}

void imp1(int n, int A[], int B[])
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(A[j]<=A[i])
			{
				B[i]=j;
				break;
			}
		}
		if(j==n)
			B[i]=-1;
	}
}
