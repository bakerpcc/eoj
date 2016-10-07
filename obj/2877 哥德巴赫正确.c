#include<stdio.h>

int ss(int i)
{int j;
if(i<=1) return 0;
if(i==2) return 1;
for(j=2;j<i;j++)
	if(i%j==0) return 0;
return 1;
}

int main()
{int n,a,b,max,flag;
while(scanf("%d",&n)==1)
	{a=n/2;b=n/2;flag=1;
	while(flag)
		if(ss(a)&&ss(b)) {printf("%d %d\n",a,b);flag=0;}
		else {a--;b++;}
	}
return 0;
}