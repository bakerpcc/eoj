#include<stdio.h>
int main()
{
	long a,sum,b,j,count;
	int group,gewei,shiwei,baiwei,temp;
	int i,new_gewei;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{
		scanf("%ld",&a);
		sum=count=0;
		b=a;
		while(b>0)
		{
			sum+=b%10;b/=10;count++;
		}
		b=a;
		shiwei=b%100/10;
		baiwei=b%1000/100;
		gewei=b%10;
		for(j=0;j<=a-count;j++)
		{
			new_gewei=((shiwei+baiwei)*gewei)%10;
			if(new_gewei==0) break;//这一步很关键，关乎到是否超时。
			sum+=new_gewei;
			baiwei=shiwei;
			shiwei=gewei;
			gewei=new_gewei;
		}
		printf("case #%d:\n%d\n",i,sum);
	}
return 0;
}