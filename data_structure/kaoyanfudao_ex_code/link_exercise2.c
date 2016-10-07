#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	//int data;
	char data;
	struct node *link;
}NODE;

void *DePatch1(NODE*L1,NODE *L2)
{
	NODE *p,*r,*u;
	int i=1;
	//L2=(NODE*)malloc(sizeof(NODE));
	L2->link=L2;
	p=L1->link;
	L1->link=L1;
	r=L1;
	while(p!=L1)
	{
		if(i%2==1)
		{
			u=p->link;
			r->link=p;r=p;r->link=L1;
			p=u;i++;
		}
		else
		{
			u=p->link;
			p->link=L2->link;L2->link=p;
			p=u;i++;
		}
	}
	//return L2;
}

void DePatch2(NODE*L1,NODE*L2)
{
	NODE *pre,*p;
	int i=1;
	//L2=(NODE*)malloc(sizeof(NODE));
	L2->link=L2;
	pre=L1;p=L1->link;
	while(p!=L1)
	{
		if(i%2==1)
		{
			pre->link=p->link;
			p->link=L2->link;
			L2->link=p;
		}
		else
			pre=p;
		p=pre->link;
		i++;
	}
}

int main()
{
	NODE *ah,*p,*q,*bh;
	int n,i;
	ah=(NODE*)malloc(sizeof(NODE));
	bh=(NODE*)malloc(sizeof(NODE));
	//p=(NODE*)malloc(sizeof(NODE));
	//ah->link=p;
	p=ah;

	scanf("%d",&n);
	scanf(" ");
	for(i=0;i<n;i++)
	{
		//scanf("%c",&(p->data));
		q=(NODE*)malloc(sizeof(NODE));
		scanf("%c",&(q->data));
		p->link=q;
		p=q;
	}
	p->link=ah;
	for(p=ah->link;p!=ah;p=p->link)
		printf("%c",p->data);
	printf("\n");

	DePatch1(ah,bh);

	for(p=ah->link;p!=ah;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");

	for(p=bh->link;p!=bh;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");
}
//这里两个DePatch都可以用