#include<stdio.h>
void selection(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        int m=0;
        int j;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[m])
            {
                m=j;
            }
        }
        if(a[j]<a[m])
        {
            int temp=a[j];
            a[j]=a[m];
            a[m]=temp;
        }
    }
}
int main()
{
    int arr[]={243,1,23,213};
    selection(arr,4);
    for(int i=0;i<4;i++)
    {
        printf("%d ",arr[i]);
    }
}