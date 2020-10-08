//_xxx , xxx indicates min or max heap.
//deletemin is deleting min element of min heap. delete_min is deleting any element of min heap

void swap(int * a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bottomup_min(int* H, int i) //min
{
	int p;
	p = (i-1)/2;
	while((p>=0) && (H[p]>H[i]))
	{
		swap(&H[p], &H[i]);
		i=p;
		p=(i-1)/2;
	}
}

void bottomup_max(int* H, int i) //max
{
	int p;
	p = (i-1)/2;
	while((p>=0) && (H[p]<H[i]))
	{
		swap(&H[p], &H[i]);
		i=p;
		p=(i-1)/2;
	}
}

void add_min(int* H, int* n, int x)  //min
{
	H[n]=x;
	n++;
	bottomup_min(H, n-1);
}

void add_max(int* H, int* n, int x)  //max
{
	H[n]=x;
	n++;
	bottomup_max(H, n-1);
}

void topdown_min(int* H, int n, int i)  //min
{
	while(2*i+2<n)
	{
		if(H[2*i+1]<H[2*i+2])
			l=2*i+1;
		else
			l=2*i+2;
		if(H[i]>H[l])
		{
			swap(&H[i], &H[l]);
			i=l;
		}
		else
			break;
	}
	if((2*i+1<n) && H[i]>H[2*i+1])
	{
		swap(&H[i], &H[2*i+1]);
	}
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

int deletemin(int* H, int* n)  //min
{
	int min = H[0];
	H[0]=H[n-1];
	n--;
	topdown_min(H, n, 0);
	return min;
}

int deletemax(int* H, int* n)  //max
{
	int max = H[0];
	H[0]=H[*n-1];
	*n--;
	topdown_max(H, *n, 0);
	return max;
}

void update_min(int* H, int n, int i, int x)
{
	if(x>H[i])  //increase key
	{
		H[i]=x;
		topdown_min(H, n, i);
	}
	else if(x<H[i])  //decrease key
	{
		H[i]=x;
		bottomup_min(H, i);
	}
}

void build_min(int* H, int n)  //min
{
	for(int i=n/2; i>=0; i--)
	{
		topdown_min(H, n, i);
	}
}

void build_max(int* H, int n)  //max
{
	for(int i=n/2; i>=0; i--)
	{
		topdown_max(H, n, i);
	}
}
