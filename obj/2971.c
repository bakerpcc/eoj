#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{int group,i,j,count;
int len,digit;
scanf("%d",&group);
for(i=0;i<group;i++){
	scanf("%d %d",&len,&digit);
	count=0;
	for(j=pow(10.0,len-1);j<pow(10.0,len);j++)
		if((j%10==digit)&&(j%3==0)) {count++;}
	printf("\ncase #%d:\n%d\n",i,count);
	}
return 0;
}