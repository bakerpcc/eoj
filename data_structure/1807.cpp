#include<stdio.h>
#define MAXN 20000

void quick(int a[],int low,int up)
{
	int i,j,t;
	if(low<up)
	{
		i=low;
		j=up;
		t=a[low];
		while(i!=j)
		{
			while(i<j&&a[j]>t) j--;
			if(i<j) a[i++]=a[j];
			while(i<j&&a[i]<=t) i++;
			if(i<j) a[j--]=a[i];
		}
		a[i]=t;
		quick(a,low,i-1);
		quick(a,i+1,up);
	}
}

int main()
{
	int n,a[MAXN],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick(a,0,n-1);

	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}