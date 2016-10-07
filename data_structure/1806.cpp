#include<stdio.h>
#define MAXN 1024

void selection_sort(int a[],int n)
{
	int i,j,k;
	int t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]>a[j]) k=j;
		t=a[i];
		a[i]=a[k];
		a[k]=t;
	}
}

int main()
{
	int n,a[MAXN],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selection_sort(a,n);

	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}