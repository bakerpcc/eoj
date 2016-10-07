#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int i,j,v;
}triple;

int cmp(const void *a,const void *b)
{
	triple* s1=(triple*)a;
	triple* s2=(triple*)b;
	if(s1->j!=s2->j)
		return s1->j-s2->j;
	else
		return s1->i-s2->i;
}

int main()
{
	int m,n,t,k;
	triple *a;
	scanf("%d%d%d",&m,&n,&t);
	a=(triple*)malloc(t*sizeof(triple));
	for(k=0;k<t;k++)
		scanf("%d %d %d",&a[k].i,&a[k].j,&a[k].v);
	qsort(a,t,sizeof(triple),cmp);
	for(k=0;k<t;k++)
		printf("%d %d %d\n",a[k].j,a[k].i,a[k].v);
	return 0;
}