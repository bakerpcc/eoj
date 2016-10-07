
#include<stdio.h>
#include<stdlib.h>
#define MAXN 64
 
typedef struct node{
int data;
struct node *link;
}NODE;
 
NODE *head,*p,*q,*s;
 
/*NODE*create_link_list(int n)
{
	int i;
	NODE*head,*p,*q;
	if(n==0) return NULL;
	head=(NODE*)malloc(sizeof(NODE));
	p=head;
	for(i=1;i<n;i++)
	{
		scanf("%d",&(p->data));
		q=(NODE*)malloc(sizeof(NODE));
		p->link=q;
		p=q;
	}
	p->link=NULL;
	return head;
}*/
 
void insert(NODE**p_head,int a,int b)
{
	NODE*p,*q;
	q=(NODE*)malloc(sizeof(NODE));
	q->data=b;
	q->link=NULL;
	if(*p_head==NULL)
		*p_head=q;
	else
	{p=*p_head;
	while(p->data!=a&&p->link!=NULL)
		p=p->link;
	q->link=p->link;
	p->link=q;
	}
}
 
 
int main()
{
	int n,qq,v,pre,cur;
	int i,j,k;
	
	scanf("%d",&n);
	if(n==0) return NULL;
	head=(NODE*)malloc(sizeof(NODE));
	p=head;
	for(i=1;i<n;i++)
	{
		scanf("%d",&(p->data));
		q=(NODE*)malloc(sizeof(NODE));
		p->link=q;
		p=q;
	}
	scanf("%d",&(p->data));
	//getchar();
	p->link=NULL;
 
	//create_link_list(n);
 
	/*p=head;
	while(p->link!=NULL)
	{printf("%d",p->data);p=p->link;}*/
 
	scanf("%d",&qq);
 
	for(i=0;i<qq;i++)
	{
		scanf("%d %d",&pre,&cur);
		insert(&head,pre,cur);
		printf("%d",head -> data);
		p=head->link;
		while(p->link!=NULL)
		{printf(" %d",p->data);p=p->link;}
		printf(" %d\n",p->data);
	}
	return 0;
}
 


