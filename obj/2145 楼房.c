#include<stdio.h>
int main()
{
	int n,i,h,sum,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{scanf("%d",&h);sum=0;
		for(j=0;h>=0;j++,h--)
			sum+=(4*2*j+4)*h;
		printf("%d\n",sum);
		}
	return 0;
}