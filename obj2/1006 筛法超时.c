#include<stdio.h>
#include<math.h>

#define MAX 1000001

int a[MAX]={0};

int main()
{long m,n;
int i,j,count;
for(i=0;i<=MAX;i++)
	a[i]=i;
a[0]=0;a[1]=0;
for(i=2;i<sqrt(1.0*MAX);i++)
	{for(j=i+1;j<=MAX;j++)
		{if((a[i]!=0)&&(a[j]!=0))
		if(a[j]%a[i]==0) a[j]=0;
		}
	}
while(scanf("%ld%ld",&m,&n)==2)
	{count=0;
	for(i=m;i<=n;i++)
		if(a[i]!=0) count++;
	printf("%d\n",count);
	}
}