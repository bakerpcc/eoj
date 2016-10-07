#include<stdio.h>
int main()
{int m,i,s;
for(m=2;m<4000;m++)
	{s=0;
	for(i=1;i<m;i++) if((m%i)==0) s=s+i;
	if(s==m)
	{printf("%d its factors are",m);
	for(i=1;i<m;i++)
		if((m%i)==0) printf(" %d",i);
	printf("\n");
	}
	}
return 0;
}