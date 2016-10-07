#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{return *(int*)a-*(int*)b;}

int del(int *s,int *a,int n)
{int *p;
int i,k=1;
a[0]=s[0];
for(i=1;i<n;i++)
	if(s[i]!=s[i-1]) {a[k++]=s[i];}
return k;
}

int huzhi(int n,int m)
{if(n%m==0) return 0;
else return 1;
}

int main()
{int n,s[500],a[500],i=0,k,j,m,count=0;

scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&s[i]);

qsort(s,n,sizeof(int),cmp);

k=del(s,a,n);
//printf("%d",k);
//for(i=0;i<k;i++) printf("%d",a[i]);
for(i=0;i<k;i++)
	for(j=i+1;j<k;j++)
		for(m=j+1;m<k;m++)
			if((huzhi(i,j)&&huzhi(i,m)&&huzhi(j,m))||!(huzhi(i,j)&&!huzhi(i,m)&&!huzhi(j,m)))
				count++;
printf("%d\n",count);
return 0;
}