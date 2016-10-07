#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000000
#define MAXM 1000000
struct l_node
{
	int ver;
	struct l_node* link;
};
typedef struct l_node L_NODE;
typedef struct
{
	int ver1;
	int ver2;
}E_NODE;

L_NODE *head[MAXN];
int visit[MAXN];
E_NODE e[MAXM];
int n,m,u;

void create_adj_list(L_NODE *head[],int n,E_NODE e[],int m)
{
	int i,u,v;
	L_NODE *p;
	for(i=1;i<=n;i++)
		head[i]=NULL;
	for(i=0;i<m;i++)
	{
		u=e[i].ver1;
		v=e[i].ver2;
		p=(L_NODE*)malloc(sizeof(L_NODE));
		p->ver=v;
		p->link=head[u];
		head[u]=p;
		p=(L_NODE*)malloc(sizeof(L_NODE));
		p->ver=u;
		p->link=head[v];
		head[v]=p;
	}
}

void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
		visit[i]=0;
}

void dfs(int u)	
{
	L_NODE *t;
	visit[u]=1;
	//printf("%4d",u);
	t=head[u];
	while(t!=NULL)
	{
		if(visit[t->ver]==0)
			dfs(t->ver);
		t=t->link;
	}
}

int main()
{
	int n1,m1,i,j;
	scanf("%d %d",&n1,&m1);
	for(i=0;i<m1;i++)
		scanf("%d %d",&e[i].ver1,&e[i].ver2);
	create_adj_list(head ,n1,e,m1);
	dfs(2);
	for(i=1;i<=n1;i++)
		if(visit[i]!=1) break;
	if(i>n1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}