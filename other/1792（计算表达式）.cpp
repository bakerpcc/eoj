#include<stdio.h>
#include<ctype.h>
#include<assert.h>

char str[1024];
int a[1024];
int c;

int getnum()
{
	int ret=0;
	while(isdigit(str[c]))
	{
		ret=ret*10+str[c]-'0';
		c++;
	}
	return ret;
}

int main()
{
	int i,j,s;
	while(gets(str))
	{
		c=0;
		s=1;
		if(str[c]=='-')
		{
			c++;
			s=-1;
		}
		for(j=0;;)
		{
			int t=getnum();
			while(str[c]=='*'||str[c]=='/')
			{
				char op=str[c];
				c++;
				int t1=getnum();
				if(op=='*')
					t*=t1;
				else
					t/=t1;
			}
			a[j++]=s*t;
			if(str[c]=='-')
				s=-1;
			else if(str[c]=='+')
				s=1;
			else break;
			c++;
		}
		s=0;
		for(i=0;i<j;i++)
		{
			s+=a[i];
		}
		printf("%d\n",s);
	}
	return 0;
}