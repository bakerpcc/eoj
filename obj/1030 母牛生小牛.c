#include<stdio.h>
void cow(int n);
int main()
{int n;
while(scanf("%d",&n)==1 && n > 0) cow(n);
return 0;
}
void cow(int n)
{int i,sum=0,a[5];
for(i=1;i<=n;i++)
	{if(i==1) {a[1]=1;a[2]=a[3]=a[4]=0;}
	else if(i==2) {a[1]=0;a[2]=1;a[3]=a[4]=0;}
	else if(i==3) {a[1]=a[2]=0;a[3]=1;a[4]=0;}
	else {a[4]=a[3]+a[4];a[3]=a[2];a[2]=a[1];a[1]=a[4];}
	}
for(i=1;i<=4;i++) sum=sum+a[i];
printf("%d\n",sum);
}//1��ĸţ��Ϊa[1],2��ĸţ��Ϊa[2],3��ĸţ��Ϊa[3],4���4������ĸţ��Ϊa[4]��

