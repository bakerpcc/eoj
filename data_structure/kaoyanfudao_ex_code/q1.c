#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	//int data;
	char data;
	struct node *link;
}
NODE;

void Adjust(NODE *A,NODE *B,NODE *D)
{
	NODE *pre,*p;

	pre=A; // pre��ͷָ��
	p=A->link; // p��ָ���һ���ڵ��ָ��
	while(p!=A) // p == Aʱ����ʾ�����ֻص���ͷ�ڵ��ˣ�ѭ������
	{
		if((p->data>='a')&&(p->data<='z')||(p->data>='A')&&(p->data<='Z')){ // ��ĸ���������B�������ǵ��Ų��������
			pre->link=p->link;
			p->link=B->link;
			B->link=p;
		}
		else if ((p->data>='0')&&(p->data<='9')) // ���ֲ�������D��Ҳ�ǵ��Ų�������
		{
			pre->link=p->link;
			p->link=D->link;
			D->link=p;
		}
		else pre=p;
		p=pre->link;
	}
	// pre->link=A; // ��ú������治Ҫ�޸���Ϊ��������ݽṹ��������ʹ������������֪�������ڴ����������������ͬʱ�����޸�����������
}
int main()
{
	NODE *ah,*bh,*dh,*p,*q;
	int i,n;
	ah=(NODE*)malloc(sizeof(NODE));
	bh=(NODE*)malloc(sizeof(NODE));
	bh->link = bh; // ��Ҫ�ں�������ͬʱ����ڵ㣬�����޸�����Ľṹ�����ͷ����ѭ������,Ӧ�ô�����֮���ٴ��ݸ�����ֱ�Ӳ������ݡ�
	dh=(NODE*)malloc(sizeof(NODE));
	dh->link = dh;
	//p=(NODE*)malloc(sizeof(NODE));
	//ah->link=p;
	p = ah->link = ah; // ��ͷ����ѭ������Ϊ��ʱͷָ��ָ������
	scanf("%d",&n);
	scanf(" ");
	for(i=0;i<n;i++)
	{
		q=(NODE*)malloc(sizeof(NODE)); // �����ȷ���һ���ڵ�
		scanf("%c",&(q->data)); // ���ַ������ýڵ�
		p->link=q;
		p=q;
	}

	p->link=ah; // ����ѭ������
	for(p=ah->link;p != ah;p=p->link)
		printf("%c",p->data);
	printf("\n");
	// ���������Ķ���ͱȽ������ˣ�A��B��D��������ͷ����ѭ������A�Ǻ��������������B��D�����������
	// ������ѭ������A���б�������A�е���ĸ�ڵ��Ƴ������뵽B�У������ֽڵ��Ƴ�������D�У�����Ԫ�ر��ֲ��䡣
	Adjust(ah,bh,dh);
	for(p=ah->link;p!=ah;p=p->link) //�����������
 	{
		printf("%c ",p->data);
	}
	printf("\n");
	for(p=bh->link;p!=bh;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");
	for(p=dh->link;p!=dh;p=p->link)
	{
		printf("%c ",p->data);
	}
	printf("\n");
	//printf("%c %c %c",ah->data,bh->data,dh->data);
	return 0;
}
