#include<stdio.h>
#include<stdlib.h>

int gcd(int m,int n)
{
	if(m%n==0) return n;
	else gcd(n,m%n);
}

int cmp(const void*a,const void *b)
{return *(int*)a-*(int*)b;}

int main()
{int group,n,s[1000],s1[1000];
int i,j,j1,k,k1,k2,count;

scanf("%d",&group);
for(i=0;i<group;i++)
	{scanf("%d",&n);
	for(j=0;j<n;j++) scanf("%d",&s[j]);
	qsort(s,n,sizeof(int),cmp);

	k2=count=0;
	k1=1;

	s1[0]=s[0];
	for(j=1;j<n;j++)
		if(s[j]!=s[j-1]) s1[k1++]=s[j];
	//for(j=0;j<k1;j++)
	//printf("%d ",s1[j]);
	if(k1==1) printf("case #%d:\n%d\n",i,0);

	for(j=0;j<k1;j++)
		for(k=j+1;k<k1;k++)
			if(gcd(s1[k],s1[j])<=1) count++;
			
	printf("case #%d:\n%d\n",i,count);
	}
return 0;
}