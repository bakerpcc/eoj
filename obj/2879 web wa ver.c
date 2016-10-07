#include<stdio.h>

int main()
{int n,i,j,k,s[500],count=0;
scanf("%d",&n);
for(i=0;i<n;i++)
	scanf("%d",&s[i]);
for(i=0;i<n-2;i++)
	for(j=i+1;j<n-1;j++)
		for(k=j+1;k<n;k++)
		{if((s[k]%s[i]!=0)&&(s[k]%s[j]!=0)&&(s[j]%s[i]!=0))
		count++;
		}
printf("%d\n",count);
return 0;
}