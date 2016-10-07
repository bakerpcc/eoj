#include<stdio.h>
#include<stdlib.h>
#define M 1001

int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}


int main()
{
	int n;
	int a[M];
	int i,j;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		qsort(&a[i-1],n-i+1,sizeof(a[0]),cmp);
		sum+=a[i-1]+a[i];
		a[i]+=a[i-1];
	}
	printf("%d\n",sum);
return 0;
}