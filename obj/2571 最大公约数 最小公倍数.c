#include<stdio.h>
int main()
{int n,i,temp,p,m,r;
unsigned int a,b;
scanf("%d",&n);
for(i=0;i<n;i++)
	{scanf("%d %d",&a,&b);
	if(a<b)
	{temp=a;a=b;b=temp;}
	p=a*b;
	while(b!=0)//直到余数为0为止。
	{r=a%b;a=b;b=r;}
	printf("%d %d\n",a,p/a);
	}
return 0;
	
}