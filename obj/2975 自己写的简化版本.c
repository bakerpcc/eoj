#include<stdio.h>
#include<stdlib.h>

int cmp1(const void*a,const void *b)
{return *(int*)a-*(int*)b;}

int cmp2(const void*a,const void *b)
{int *s1=(int*)a;int *s2=(int*)b;
if((*s1%10)==(*s2%10)) return *s1-*s2;
else return ((*s1%10)-(*s2%10));
}
int main()
{int group,n,k,a[100],a_sort[100];
int i,j;
scanf("%d",&group);
for(i=0;i<group;i++)
	{scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d",&a[j]);
	qsort(a,n,sizeof(int),cmp1);
	a_sort[0]=a[0];k=1;
	for(j=1;j<n;j++)
		if(a[j]!=a[j-1]) a_sort[k++]=a[j];
	qsort(a_sort,k,sizeof(int),cmp2);
	printf("case #%d:\n",i);
	for(j=0;j<k-1;j++)
		printf("%d ",a_sort[j]);
	printf("%d\n",a_sort[j]);
	}
return 0;
}
