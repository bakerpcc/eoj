#include<stdio.h>
int main()
{int n,num,i,p,e,j,a=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%d",&num);
 for(j=2;j<=num;j++)
 {p=j;e=0;
	while(num%j==0) {e++;num=num/j;}
  if(e>0) printf("(%d,%d)",p,e);
 }
 printf("\n");
}
return 0;
}