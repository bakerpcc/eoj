#include<stdio.h>
int main()
{
	int people,group,found;
	long long money;
	int m,w,c;
	int i,j,k;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{scanf("%d %lld",&people,&money);
	found=0;
	printf("case #%d:\n",i);
	for(m=0;m<(money-people)/2+1;m++){
			w=(money-people)-2*m;
			c=(money-m*3-w*2);
			if((m+w+c==people)&&(w>=0)&&(c>=0)) {printf("%d %d %d\n",m,w,c);found=1;}
		}
	if(found==0) printf("-1\n");
	}
	return 0;
}