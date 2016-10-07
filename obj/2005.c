#include<stdio.h>
int main()
{int n,i;
while(scanf("%d",&n)==1)
	for(i=2;i<n-1;i++)
		if(n%i==0)
		{printf("%d %d\n",i,n/i);break;}
return 0;
}