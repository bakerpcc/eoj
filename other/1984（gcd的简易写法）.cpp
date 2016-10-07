#include<stdio.h>

int gcd(int n,int m)
{
	return m?gcd(m,n%m):n;
}

int main()
{
	int n,i,max,min,num;
	while(scanf("%d",&n)!=EOF)
	{
		for(max=-1000000000,min=1000000000,i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(num>max) max=num;
			if (num<min) min=num;
		}
		printf("%d %d %d\n",min,max,gcd(max,min));
	}
	return 0;
}