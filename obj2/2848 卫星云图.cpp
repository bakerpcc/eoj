#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//+2是为了把二位数组最外围一圈都标上'.'
#define W (80+2) 
#define H (1000+2)

char gp[H][W];//记录照片

// 深度优先算法
int dfs(int x,int y)
{
	int i;
	int ans;//当前一个建筑

	// 分别代表当前节点相邻的四个节点
	int dx[]={0,1,-1,0};
	int dy[]={1,0,0,-1};

	if(gp[x][y]!='*')return 0;//如果当前点不是建筑，返回0
	
	gp[x][y]='.';//表示已经搜过
	ans = 1;
	for(i = 0; i < 4; i++)
		ans += dfs(x+dx[i],y+dy[i]);//四个相邻节点继续搜索,将结果加到当前建筑的建筑群
	return ans;
}

int main2848()
{
	int i,j,cur;
	int w,h;
	int ans;//最后的答案

	while(scanf("%d%d",&w,&h) == 2)
	{
		ans=0;
		memset(gp, '.', sizeof(gp));//清空图片

		for(i = 1; i <= h; i++) // 第0行不存内容，当作边界
			scanf("%s",gp[i]+1);// 第0列不存内容，当作边界
		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)	{
				if(gp[i][j]=='*')//判断如果当前没有搜过
				{
					cur = dfs(i,j); // 当前节点的建筑群数量
					if( cur > ans)
						ans=cur;//更新答案
				}
		}
		printf("%d\n",ans);
	}

	return 0;
}