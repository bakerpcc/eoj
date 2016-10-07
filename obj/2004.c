#include<stdio.h>

int main()
{int i,a,b,c,d,t=0;
for(i=1000;i<10000;i++)
	{a=i/1000;b=i%1000/100;c=i%1000%100/10;d=i%10;
	if(i==a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d)
		{printf("%d\n",i);t++;}
	}
if(t==0)
	printf("no answer");
return 0;
}