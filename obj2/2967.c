#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{return *(int*)a-*(int*)b;
}

int main()
{
	int group,flag;
	int i,j,k,n,m,m1,m2,m3;
	int a1[100],a2[100],a3[100],record[100];
	scanf("%d",&group);
	for(n=0;n<group;n++)
	{
		scanf("%d%d%d",&i,&j,&k);
		printf("case #%d:\n",n);
		flag=m3=0;
		for(m=0;m<i;m++)
			scanf("%d",&a1[m]);
		for(m=0;m<j;m++)
			scanf("%d",&a2[m]);
		for(m=0;m<k;m++)
			{
				scanf("%d",&a3[m]);
				for(m1=0;m1<i;m1++)
					if(a3[m]==a1[m1])
						for(m2=0;m2<j;m2++)
							if(a3[m]==a2[m2]) 
								{record[m3++]=a3[m];flag=1;}
			}
		qsort(record,m3,sizeof(int),cmp);
		if(flag==1){
			for(m=0;m<m3-1;m++)
				printf("%d ",record[m]);
		printf("%d\n",record[m]);
		}
		if(flag==0) printf("-1\n");
	}
	return 0;
}