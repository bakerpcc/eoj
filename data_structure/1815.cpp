#include<stdio.h>
#include<stdlib.h>
#define MAXN 100001
struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
};
typedef struct node NODE;

NODE *addr[2*MAXN-1];//
NODE *create_huffman_tree(int w[],int n)
{
	int n1,n2,i,j;
	int u,v,min1,min2;
	for(i=0;i<n;i++)
	{
		addr[i]=(NODE*)malloc(sizeof(NODE));
		addr[i]->data=w[i];
		addr[i]->lchild=NULL;
		addr[i]->rchild=NULL;
		addr[i]->parent=NULL;
		w[i]=-w[i];
	}
	for(i=n;i<2*n-1;i++)
	{
		n1=-1;
		min1=999999999;
		n2=-1;
		min2=999999999;
		for(j=0;j<i;j++)
		{
			v=w[j];
			u=-v;
			if(u>0)
				if(u<min1)
				{
					min2=min1;
					n2=n1;
					min1=u;
					n1=j;
				}
				else if(u<min2)
				{
					min2=u;
					n2=j;
				}
		}
		addr[i]=(NODE*)malloc(sizeof(NODE));
		addr[i]->parent=NULL;
		addr[i]->lchild=addr[n1];
		addr[i]->rchild=addr[n2];
		addr[n1]->parent=addr[i];
		addr[n2]->parent=addr[i];
		w[i]=w[n1]+w[n2];
		w[n1]=-w[n1];
		w[n2]=-w[n2];
	}
	w[2*n-2]=-w[2*n-2];
	return (addr[2*n-2]);
}

int main()
{
	int n,a[MAXN],m,i;
	int sum;
	NODE *root,*p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	root=create_huffman_tree(a,n);
	sum=0;
	for(i=0;i<n;i++)
	{
		p=addr[i];
		m=0;
		while(p->parent!=NULL)
		{
			m++;
			p=p->parent;
		}
		sum=sum+m*addr[i]->data;
		}
	printf("%d\n",sum);
	return 0;
}
