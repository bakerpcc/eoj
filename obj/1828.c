#include<stdio.h>
int main()
{int n,i=0,time[3];
while(scanf("%d",&n)==1) 
	{if(n==-1) return 0;
	time[0]=n/3600;
	time[1]=(n%3600)/60;
	time[2]=(n%3600)%60;
	printf("%02d:%02d:%02d\n",time[0],time[1],time[2]);
	}
return 0;
}
