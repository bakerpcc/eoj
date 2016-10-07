#include<stdio.h>
#define MAXINT 9999
#define MAXN 601
typedef int MAT[MAXN][MAXN];
MAT cost;
int dist[MAXN],pre[MAXN],n,v;
 
void shortestpath(MAT cost,int n,int v,int dist[],int pre[])
{
	int s[MAXN],i,j,k,min;
	for(i=1;i<=n;i++)
	{
		dist[i]=cost[v][i];
		s[i]=0;
		if(dist[i]<MAXINT)
			pre[i]=v;
		else pre[i]=0;
	}
	s[v]=1;
	pre[v]=0;
	for(i=1;i<=n;i++)
	{
		min=MAXINT;
		k=0;
		for(j=1;j<=n;j++)
			if(s[j]==0)
				if(dist[j]!=0&&dist[j]<min)
				{min=dist[j];
				k=j;
				}
		if(k==0) continue;
		s[k]=1;
		for(j=1;j<=n;j++)
			if(s[j]==0&&cost[k][j]<MAXINT)
				if(dist[k]+cost[k][j]<dist[j])
				{
					dist[j]=dist[k]+cost[k][j];
					pre[j]=k;
				}
	}
}
 
int main()
{
	int n0,m,i,j,x,y,z;
	scanf("%d %d",&n0,&m);
	for(i=1;i<=n0;i++)
		for(j=1;j<=n0;j++)
		{
			if(i==j) cost[i][j]=0;
			else cost[i][j]=MAXINT;
		}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		cost[x][y]=z;
	}
 
	shortestpath(cost,n0,1,dist,pre);
 
	if(n0==1) printf("0\n");
	else if(dist[n0]==0||dist[n0]==MAXINT)
		printf("-1\n");
	else
		printf("%d\n",dist[n0]);
	return 0;
}