#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	//int data;
	char data;
	struct node *link;
}NODE;


void Adjust(NODE *A,NODE *B,NODE *D)
{
	NODE *pre,*p;
	//D=(NODE*)malloc(sizeof(NODE));D->link=D;
	//B=(NODE*)malloc(sizeof(NODE));B->link=B;
	D->link=D;
	B->link=B;
	pre=A;
	p=A->link;
	while(p)
	{
		if((p->data>='a')&&(p->data<='z')||(p->data>='A')&&(p->data<='Z')){
			pre->link=p->link;
			p->link=B->link;
			B->link=p;
		}
		else if ((p->data>='0')&&(p->data<='9'))
		{
			pre->link=p->link;
			p->link=D->link;
			D->link=p;
		}
		else pre=p;
		p=pre->link;
	}
	pre->link=A;
}

int main()
{
	NODE *ah,*bh,*dh,*p,*q;
	int i,n;
	ah=(NODE*)malloc(sizeof(NODE));
	bh=(NODE*)malloc(sizeof(NODE));
	dh=(NODE*)malloc(sizeof(NODE));
	p=(NODE*)malloc(sizeof(NODE));
	ah->link=p;

	scanf("%d",&n);
	scanf(" ");
	for(i=0;i<n;i++)
	{
		scanf("%c",&(p->data));
		q=(NODE*)malloc(sizeof(NODE));
		p->link=q;
		p=q;
	}
	p->link=NULL;

	for(p=ah->link;p;p=p->link)
		printf("%c",p->data);
	printf("\n");

	Adjust(ah,bh,dh);

	for(p=ah->link;p->link!=ah;p=p->link)//p->link!=ah;为何不是p!=ah???
	{
		printf("%c ",p->data);
	}
	printf("\n");

	for(p=bh->link;p->link!=bh;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");

	for(p=dh->link;p->link!=dh;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");

	//printf("%c %c %c",ah->data,bh->data,dh->data);

	return 0;
}