#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(const void*a,const void*b);

int main()
{
int n,a[100],b[100],i,j;
while(scanf("%d",&n)==1)
	{for(i=0;i<n;i++)
	{scanf("%d",&a[i]);b[i]=abs(a[i]);}
	qsort(b,n,sizeof(int),compare);
	for(i=0;i<n-1;i++)
		for(j=0;j<n;j++)
			if(b[i]==abs(a[j]))
				printf("%d ",a[j]);
	for(j=0;j<n;j++)
			if(b[i]==abs(a[j]))
				printf("%d",a[j]);
	printf("\n");
	}
printf("\n");
return 0;

}

int compare(const void*a,const void*b)
{return *(int*)a-*(int*)b;}