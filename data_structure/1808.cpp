#include<stdio.h>
#define MAXN 1024

void bubble_sort(int a[],int n)
{
	int i,j;
	int t;
	n--;while(n>0)
	{
		j=0;
		for(i=0;i<n;i++)
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				j=i;
			}
			n=j;
	}
}

int main()
{
	int n,a[MAXN],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble_sort(a,n);

	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}