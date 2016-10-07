#include<stdio.h>
int main()
{int m,n,a[101],b[101],i,j,flag=0;
scanf("%d",&m);
for(i=0;i<m;i++)
	scanf("%d",&a[i]);
scanf("%d",&n);
for(i=0;i<n;i++)
	scanf("%d",&b[i]);
for(i=0;i<n;i++)
	{for(j=0;j<m;j++){
		flag=0;
		if(a[j]==b[i]) {printf("yes!\n");flag=1;break; }
		}
	if(flag==0) printf("no!\n");}	
return 0;
}