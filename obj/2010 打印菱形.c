#include<stdio.h>
int main()
{
	int a,b,i,j,m,n;
	char x[500][500];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<(2*n+1);i++)
			{for(j=0;j<(2*n+1);j++)
			{
				x[i][j]=' ';
		}}
		a=0;b=2*n+1;
		for(i=n;i>=0;i--)
		{
			for(j=a;j<b;j++)
			{
				x[i][j]='*';}
			a=a+1;b=b-1;
		}//���ε��ϰ벿�֡��Ǵ��м������������ϴ�ӡ��->for(i=n;i>=0;i--)
		a=n;b=n+1;
		for(i=2*n;i>n;i--)//i>n���ʲ��ٴ�ӡ�м��������ˣ������Ǵ������ϡ�
		{
			for(j=a;j<b;j++)
			{
				x[i][j]='*';}
			a=a-1;b=b+1;
		}
		for(i=0;i<(2*n+1);i++)
			{for(j=0;j<(2*n+1);j++)
			{
				if(j==2*n)printf("%c\n",x[i][j]);
				else printf("%c",x[i][j]);
		}}
		
	}
}
