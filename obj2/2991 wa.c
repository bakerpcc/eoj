#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int r1;
	int r2;
}matrix;

int cmp(const void *a,const void *b)
{
	matrix *s1=(matrix*)a;
	matrix *s2=(matrix*)b;
	if(s1->r1!=s2->r1) return s1->r1-s2->r1;
	else return s1->r2-s2->r2;
}

int main()
{
	int group;
	int a[5][5];
	matrix b[25];
	int i,j,k,flag,max,maxj,count;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{
		count=0;
		for(j=0;j<5;j++)
			for(k=0;k<5;k++)
				scanf("%d",&a[j][k]);
		for(j=0;j<5;j++)
		{
			max=a[j][0];
			maxj=0;
			for(k=0;k<5;k++)
				if(a[j][k]>max)
				{
					max=a[j][k];
					maxj=k;
				}
				flag=1;
				for(k=0;k<5;k++)
					if(max>a[k][maxj])
					{
						flag=0;continue;
					}
				if(flag)
				{
					b[count].r1=j;b[count].r2=maxj;count++;
					//printf("%d %d\n",j,maxj);
				}
		}
		printf("case #%d:\n",i);
		if(count>0)
		{		
			qsort(b,count,sizeof(matrix),cmp);
			for(j=0;j<count;j++)
				printf("%d %d\n",b[j].r1,b[j].r2);
		}
		else
			printf("-1 -1\n");
	}
	return 0;
}