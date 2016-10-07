#include<stdio.h>

int bin_dec(int x,int n)
{if(n==0) return 1;
return x*bin_dec(x,n-1);
}

int main()
{int i,ip[9][4]={0},n,m;
char a[9][33];
scanf("%d",&n);
for(m=0;m<n;m++)
	scanf("%s",a[m]);
for(m=0;m<n;m++)
	{for(i=0;i<8;i++)
		{if(a[m][i]=='1') ip[m][0]+=bin_dec(2,7-i);}
	for(i=8;i<16;i++)
		{if(a[m][i]=='1') ip[m][1]+=bin_dec(2,15-i);}
	for(i=16;i<24;i++)
		{if(a[m][i]=='1') ip[m][2]+=bin_dec(2,23-i);}
	for(i=24;i<32;i++)
		{if(a[m][i]=='1') ip[m][3]+=bin_dec(2,31-i);}
	printf("\n%d.%d.%d.%d",ip[m][0],ip[m][1],ip[m][2],ip[m][3]);
	}
}
