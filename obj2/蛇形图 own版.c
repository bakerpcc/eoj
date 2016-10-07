#include<stdio.h>

int main()
{
	int group,a[10][10];
	int i,j,k,count;
	int bian,round;
	scanf("%d",&group);
	for(k=0;k<group;k++)
	{scanf("%d",&bian);
	printf("case #%d:\n",k);
	round=count=0;
	count++;
	while(round<=bian/2)
	{for(i=j=round;j<bian-round;count++,j++)
		a[i][j]=count;
	j--;i++;
	for(/*i=round,j=bian-round*/;i<bian-round;count++,i++)
		{a[i][j]=count;/*printf("i:%d j:%d count:%d",i,j,count);*/}
	i--;j--;
	for(;j>=round;count++,j--)
		a[i][j]=count;
	j++;i--;
	for(;i>round;i--,count++)
		a[i][j]=count;
	round++;
	}
	for(i=0;i<bian;i++){
		for(j=0;j<bian-1;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][j]);
		}	
	}
	return 0;
}