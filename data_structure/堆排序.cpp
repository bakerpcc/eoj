#include<stdio.h>
#define MAX 50

void siftdown(int a[MAX],int i,int n)
{
	int j;
	int t;
	t=a[i];
	while((j=2*i+1)<n)
	{
		if(j+1<n&&a[j]<a[j+1]) j++;
		if(t<a[j])
		{
			a[i]=a[j];
			i=j;
		}
		else break;
	}
	a[i]=t;
}

void heap_sort(int a[MAX],int n)
{
	int i,t;
	for(i=(n-2)/2;i>=0;i--)
		siftdown(a,i,n);
	for(i=n-1;i>0;i--)
	{
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		siftdown(a,0,i);
	}
}

int main()
{
	int a[MAX];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heap_sort(a,n);
	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}