#include<stdio.h>
#include<stdlib.h>
int main()
{int n,i,j,k,m,group,count;
int a[80][80];
scanf("%d",&group);
for(count=0;count<group;count++)
{scanf("%d",&n);
a[0][0]=1;
for(i=1;i<n;i++)
	{a[i][i]=i*i+(i+1);
	if((i%2)!=0)
		{m=1;
		for(j=i-1;j>=0;j--)
			{a[j][i]=a[i][i]-m;m++;}
		m=1;
		for(k=i-1;k>=0;k--)
			{a[i][k]=a[i][i]+m;m++;}
		}
	else
		{m=1;
		for(j=i-1;j>=0;j--)
			{a[j][i]=a[i][i]+m;m++;}
		m=1;
		for(k=i-1;k>=0;k--)
			{a[i][k]=a[i][i]-m;m++;}
		}
	}
printf("case #%d:\n",count);
for(i=0;i<n;i++)
	{for(j=0;j<n-1;j++)
	{printf("%d ",a[i][j]);}
	printf("%d\n",a[i][j]);
	}
}
return 0;
}