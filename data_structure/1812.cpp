#include<stdio.h>
 
int main()
{
	int n,j,j1,count,lc,rc,tag,nzero,nzero1;
	scanf("%d",&n);
	count=0;j=0;nzero=1;
	while(j<n)
	{
		tag=0;
		for(nzero1=0,j1=0;j1<nzero;j1++)
			{scanf("%d %d",&lc,&rc);
			if(lc!=0) {tag=1;j++;nzero1++;}
			if(rc!=0) {tag=1;j++;nzero1++;}
			}
		if(tag==1) count++;
		if(j==n-1&&tag==0) j++;
		nzero=nzero1;
	}
	
	printf("%d\n",count+1);
	return 0;
}