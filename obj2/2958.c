#include<stdio.h>
 
struct data
{
	int a;
	int sum;
};
 
int main1()
{
	int t,i,n,j,k,max;
	struct data s[5000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			max=0;
			scanf("%d",&s[j].a);
			s[j].sum=s[j].a;
			for(k=j-1;k>=0;k--)
				if(s[k].a<s[j].a&&(s[j].a+s[k].sum)>s[j].sum)
					s[j].sum=s[j].a+s[k].sum;
		}
		for(j=0;j<n;j++)
			if(s[j].sum>max)
				max=s[j].sum;
		printf("case #%d:\n",i);
		printf("%d\n",max);
	}
	return 0;
}
 
 
