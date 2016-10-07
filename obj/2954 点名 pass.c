#include<stdio.h>
int main()
{
	int group,row,col,count;
	int i,j,m,n;
	char a[1000][1000];
	scanf("%d",&group);
	for(i=0;i<group;i++){
		count=0;
		scanf("%d %d",&row,&col);
		scanf(" ");
		for(m=0;m<row-1;m++){
			for(n=0;n<col;n++)
				{scanf("%c",&a[m][n]);
				}
			scanf(" ");
		}
		for(n=0;n<col;n++)
		{scanf("%c",&a[m][n]);}
		/*fflush(stdin);*/
		for(m=0;m<row;m++)
			for(n=0;n<col;n++)
			{if(a[m][n]=='.') count++;}
		printf("case #%d:\n%d\n",i,count);
	}
return 0;		
}