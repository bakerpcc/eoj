#include<stdio.h>
#include<string.h>
#define MAXN 100001

long long q[MAXN];
char order[8];
int head=0,tail=0;

int en_c_q(long long x)
{
	tail=(tail+1)%MAXN;
	if(tail==head)
	{
		if(tail==0) tail=MAXN-1;
		else tail--;
		return(1);//¶ÓÂú
	}
	q[tail]=x;
	return 0;
}

int de_c_q(long long*p_y)
{
	if(head==tail)
		return 1;
	head=(head+1)%MAXN;
	*p_y=q[head];
	return 0;
}

int main()
{
	int n;
	int i,j,k;
	long long num;
	long long rec;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",order);
		if(strcmp(order,"enqueue")==0)
		{
			scanf("%lld",&num);
			en_c_q(num);
		}
		else if(strcmp(order,"dequeue")==0)
			if((de_c_q(&rec)!=1))
				printf("%lld\n",rec);
			else
				printf("-1\n");
	}
return 0;
}