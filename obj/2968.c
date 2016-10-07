#include<stdio.h>
int main()
{int group,i,total,v[6];
scanf("%d",&group);
for(i=0;i<group;i++){
	scanf("%d",&total);
	v[0]=v[1]=v[2]=v[3]=v[4]=v[5]=0;
	v[0]=total/100;total=total%100;
	v[1]=total/50;total=total%50;
	v[2]=total/20;total=total%20;
	v[3]=total/10;total=total%10;
	v[4]=total/5;total=total%5;
	v[5]=total/1;total=total%1;
	
	printf("case #%d:\n%d %d %d %d %d %d\n",i,v[0],v[1],v[2],v[3],v[4],v[5]);
	}
return 0;
}