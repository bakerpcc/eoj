#include<stdio.h>
#define MAXINT 9999
#define MAXN 101
typedef int MAT[MAXN][MAXN];
MAT cost;
int dist[MAXN],record[MAXN][MAXN];
int tag;

void shortestpath(int n0)
{
	int i,j,k;
	tag=0;
	for(k=1;k<=n0;k++)
		for(i=1;i<=n0;i++)
			for(j=1;j<=n0;j++)
			{
				if(i!=j&&j!=k&&i!=k){
				if(cost[i][k]+cost[k][j]<cost[i][j])
				{
					cost[i][j]=cost[i][k]+cost[k][j];
					record[i][j]=record[i][k]*record[k][j];
					if(i==1&&j==n0)
						tag=1;
				}
				else if(cost[i][j]==cost[i][k]+cost[k][j])
				{
					record[i][j]+=record[i][k]*record[k][j];
					if(i==1&&j==n0)
						tag=1;
				}
			}
			}
}

int main()
{
	int n0,m,i,j,x,y,z;
	scanf("%d %d",&n0,&m);
	for(i=0;i<=n0;i++)
		for(j=0;j<=n0;j++)
		{
			if(i==j) cost[i][j]=0;
			else cost[i][j]=MAXINT;
			record[i][j]=0;
		}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(cost[x][y]==z)
		{
			record[x][y]++;
			continue;
		}
		cost[x][y]=z;
		record[x][y]=1;
	}

	shortestpath(n0);

	if(n0==1) printf("0\n");
	else if(tag==0)
		printf("-1 0\n");
	else
		printf("%d %d\n",cost[1][n0],record[1][n0]);
	return 0;
}

