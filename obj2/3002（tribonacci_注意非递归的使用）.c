
#include<stdio.h>

int main()
{
	int num,n;
	int i,j,k;
	long long ti[100]={0,1,1};
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&n);
		for(j=3;j<=n;j++)
			ti[j]=ti[j-1]+ti[j-2]+ti[j-3];
		printf("case #%d:\n%lld\n",i,ti[n]);
	}
	return 0;
}