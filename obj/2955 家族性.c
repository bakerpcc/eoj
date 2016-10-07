#include<stdio.h>
#include<stdlib.h>

int main()
{
	int group,a,b,i,yinzi1[500],yinzi2[500],j,k,m,j1,flag;
	
	scanf("%d",&group);
	for(i=0;i<group;i++)
		{scanf("%d %d",&a,&b);
		flag=1;
		k=0;m=0;
		j=2;
		while(a/j>0) {if(a%j==0){yinzi1[k++]=j;a=a/j;}
					else j++;}
		j=2;
		while(b/j>0) {if(b%j==0){yinzi2[m++]=j;b=b/j;}
					else j++;}
		for(j=0;j<k&&flag==1;j++)
			for(j1=0;j1<m;j1++)
				if(yinzi1[j]==yinzi2[j1])
				{printf("case #%d:\nYes %d\n",i,yinzi1[j]);flag=0;break;}
		if(flag!=0) printf("case #%d:\nNo\n",i);
		}
	return 0;
}
	

		
	