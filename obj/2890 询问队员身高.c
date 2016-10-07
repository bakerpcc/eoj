#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b);
int main()
{int group,duiyuan_num,ask_num,h[50],h1[50],ask_a[50],index[50];
int i,j,k;
scanf("%d",&group);
for(i=0;i<group;i++)
	{scanf("%d %d",&duiyuan_num,&ask_num);
	for(j=0;j<duiyuan_num;j++)
		{scanf("%d",&h[j]);h1[j]=h[j];}
	for(k=0;k<ask_num;k++)
		scanf("%d",&ask_a[k]);
	qsort(h,duiyuan_num,sizeof(int),cmp);

	for(k=0;k<ask_num-1;k++)
		{for(j=0;(h[ask_a[k]-1]!=h1[j]);j++) ;
		printf("%d ",j+1);}
	{for(j=0;(h[ask_a[k]-1]!=h1[j]);j++) ;
		printf("%d\n",j+1);}
	
	}
return 0;
}
int cmp(const void *a,const void *b)
{return *(int*)b-*(int*)a;}