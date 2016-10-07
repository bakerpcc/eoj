#include<stdio.h>
#include<stdlib.h>
#define MAXM 10
#define MAXN 27
 
struct node{
	int lev;
	char data;
	struct node *child[MAXM];
	struct node *parent;
};
typedef struct node NODE;
typedef struct dnode {
	int lev;
	char data;
}DNODE;
DNODE a[MAXN];
 
NODE* lev_tree(int n)
{
	int i,j;
	NODE *root,*p,*q;
	if(n<1)return(NULL);
	root=(NODE*)malloc(sizeof(NODE));
	root->lev=a[0].lev;
	root->data=a[0].data;
	for(i=0;i<MAXM;i++)
		root->child[i]=NULL;
	root->parent=NULL;
	p=root;
	for(i=1;i<n;i++)
	{
		q=(NODE*)malloc(sizeof(NODE));
		q->lev=a[i].lev;
		q->data=a[i].data;
		for(j=0;j<MAXM;j++)
			q->child[j]=NULL;
		while(q->lev<=p->lev)
			p=p->parent;
		q->parent=p;
		j=-1;
		while(p->child[++j]!=NULL) ;
		p->child[j]=q;
		p=q;
	}
return (root);
}
 
/*int cmp(const void *a,const void *b)
{
	DNODE*s1=(DNODE*)a;
	DNODE*s2=(DNODE*)b;
	return s1->lev-s2->lev;
}*/
void after_order(NODE *root) //m叉树的非递归后序遍历
{
 NODE *stack[MAXN],*p;
 int mark[MAXM];
 int top = -1,j;
 stack[++top] = root;
 mark[top] = 0;
 while(top>=0)
 {
  p = stack[top];
  if(mark[top]==0&&p->child[0]!=NULL)
  {
   mark[top] = 1;
   for(j=MAXM-1;j>=0;j--)
   {
    if(p->child[j]!=NULL)
    {
     stack[++top] = p->child[j];
     mark[top] = 0;
    }
   }
  }
  if(stack[top]->child[0]==NULL||mark[top]==1)
   printf("%c",stack[top--]->data);
 }
}
 
int main()
{
	int n,i;
	char c1,c2;
	NODE *root=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&n);
	scanf(" ");
	for(i=0;i<n;i++)
		{
			getchar();
			scanf("%d,%c",&a[i].lev,&a[i].data);
			getchar();
			getchar();
		}
	/*for(i=0;i<n;i++)
		{printf("(%d,%c)",a[i].lev,a[i].data);
		}*/
	root=lev_tree(n);
	after_order(root);
	printf("\n");
	return 0;
}
