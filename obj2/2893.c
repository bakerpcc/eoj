#include<stdio.h>
#include<string.h>

int gcd(int m,int n)
{
	if(m%n==0) return n;
	else gcd(n,m%n);
}

int main()
{
	int group,count,size;
	int i,c1,n; 
	char s[500],*p,c,t[2];
	scanf("%d ",&group);
	for(i=0;i<group;i++)
	{
		size = count = 0;
		gets(s);
		p=s;
		while(*p!=NULL){
			size += 8; // 每个字节8位
			for (c1 = 0; c1 < 8; c1++) // 判断该字节有多少个1，从0位循环到7位
				if ((1<<c1) & *p) // 1右移cl位刚好是该位为1而其他位为0的掩码，与当前字符*p按位&操作后，如果*p的该位为1，结果必然>0,否则=0
					count++;
			p++;
		}

		n=gcd(size,count);
		printf("%d/%d\n",count/n,size/n);
	}
	return 0;
}
