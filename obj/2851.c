#include<stdio.h>

int reverse(int n);

int main()
{int n,m,s,count=1;
scanf("%d",&n);
m=reverse(n);
s=m+n;
while(s!=reverse(s))
	{s=s+reverse(s);
	count++;
	}
printf("%d %d",count,s);
}

int reverse(int n)
{int result=0,r;
while(n>0)
	{
	result=result*10+n%10;//ÄæĞò´æ·Å
	n=n/10;
	}
return result;
}