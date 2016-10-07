#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//+2��Ϊ�˰Ѷ�λ��������ΧһȦ������'.'
#define W (80+2) 
#define H (1000+2)

char gp[H][W];//��¼��Ƭ

// ��������㷨
int dfs(int x,int y)
{
	int i;
	int ans;//��ǰһ������

	// �ֱ����ǰ�ڵ����ڵ��ĸ��ڵ�
	int dx[]={0,1,-1,0};
	int dy[]={1,0,0,-1};

	if(gp[x][y]!='*')return 0;//�����ǰ�㲻�ǽ���������0
	
	gp[x][y]='.';//��ʾ�Ѿ��ѹ�
	ans = 1;
	for(i = 0; i < 4; i++)
		ans += dfs(x+dx[i],y+dy[i]);//�ĸ����ڽڵ��������,������ӵ���ǰ�����Ľ���Ⱥ
	return ans;
}

int main2848()
{
	int i,j,cur;
	int w,h;
	int ans;//���Ĵ�

	while(scanf("%d%d",&w,&h) == 2)
	{
		ans=0;
		memset(gp, '.', sizeof(gp));//���ͼƬ

		for(i = 1; i <= h; i++) // ��0�в������ݣ������߽�
			scanf("%s",gp[i]+1);// ��0�в������ݣ������߽�
		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)	{
				if(gp[i][j]=='*')//�ж������ǰû���ѹ�
				{
					cur = dfs(i,j); // ��ǰ�ڵ�Ľ���Ⱥ����
					if( cur > ans)
						ans=cur;//���´�
				}
		}
		printf("%d\n",ans);
	}

	return 0;
}