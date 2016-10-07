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

	pre=A; // pre是头指针
	p=A->link; // p是指向第一个节点的指针
	while(p!=A) // p == A时，表示链表又回到表头节点了，循环结束
	{
		if((p->data>='a')&&(p->data<='z')||(p->data>='A')&&(p->data<='Z')){ // 字母则插入链表B，这里是倒着插入链表的
			pre->link=p->link;
			p->link=B->link;
			B->link=p;
		}
		else if ((p->data>='0')&&(p->data<='9')) // 数字插入链表D，也是倒着插入链表
		{
			pre->link=p->link;
			p->link=D->link;
			D->link=p;
		}
		else pre=p;
		p=pre->link;
	}
	// pre->link=A; // 最好函数里面不要修改做为输入的数据结构，函数的使用者往往不会知道函数在创建了两个新链表的同时，还修改了输入链表
}
int main()
{
	NODE *ah,*bh,*dh,*p,*q;
	int i,n;
	ah=(NODE*)malloc(sizeof(NODE));
	bh=(NODE*)malloc(sizeof(NODE));
	bh->link = bh; // 不要在函数里面同时插入节点，并且修改链表的结构（如带头结点的循环链表）,应该创建好之后再传递给函数直接插入数据。
	dh=(NODE*)malloc(sizeof(NODE));
	dh->link = dh;
	//p=(NODE*)malloc(sizeof(NODE));
	//ah->link=p;
	p = ah->link = ah; // 带头结点的循环链表，为空时头指针指向自身
	scanf("%d",&n);
	scanf(" ");
	for(i=0;i<n;i++)
	{
		q=(NODE*)malloc(sizeof(NODE)); // 这里先分配一个节点
		scanf("%c",&(q->data)); // 将字符读到该节点
		p->link=q;
		p=q;
	}

	p->link=ah; // 构成循环链表
	for(p=ah->link;p != ah;p=p->link)
		printf("%c",p->data);
	printf("\n");
	// 这样函数的定义就比较清晰了：A、B、D是三个带头结点的循环链表，A是函数的输入参数，B和D是输出参数。
	// 函数对循环链表A进行遍历，将A中的字母节点移除并插入到B中，将数字节点移除并插入D中，其他元素保持不变。
	Adjust(ah,bh,dh);
	for(p=ah->link;p!=ah;p=p->link) //问题就在这里
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
