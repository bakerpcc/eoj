#include<stdio.h>
#include<stdlib.h>

int main()
{int n,/*a[100][100],*/**a,i,j,k;
while(scanf("%d",&n)==1){
a=(int **)malloc(n*sizeof(int *));
for(i=0;i<n;i++)
	a[i]=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		a[i][j]=0;
j=n/2;
a[n-1][j]=1;
for(k=2;k<=n*n;k++)
	{i=i+1;j=j-1;
if((i>n-1)&&(j<0))
	{i=i-2;j=j+1;}
else
{if(i>n-1) i=0;
if(j<0) j=n-1;}
if(a[i][j]==0) a[i][j]=k;
else{i=i-2;j=j+1;a[i][j]=k;}
	}
for(i=0;i<n;i++)
{for(j=0;j<n-1;j++)
printf("%d ",a[i][j]);
printf("%d\n",a[i][j]);
}
}
return 0;
}