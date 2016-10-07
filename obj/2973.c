#include<stdio.h>
int main()
{int group,i,j,N,M,k,k1,k2,k3,sum,max;
long a[100];
scanf("%d",&group);
for(i=0;i<group;i++)
	{scanf("%d %d",&N,&M);
	for(j=0;j<N;j++)
		scanf("%d",&a[j]);
	max=0;
	for(k1=0;k1<N-2;k1++)
		for(k2=k1+1;k2<N-1;k2++)
			for(k3=k2+1;k3<N;k3++)
				{
				sum=a[k1]+a[k2]+a[k3];
				if((sum>max)&&sum<=M)
					max=sum;
				}	
			printf("case #%d:\n%d\n",i,max);
	}
return 0;
}