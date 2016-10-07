#include<stdio.h>
#include<stdlib.h>

int main()
{int n;
char /***a*/a[500][500]={0};
int i,j;
while(scanf("%d",&n)==1)
	{/*a=(char**)malloc((2*n+1)*(2*n+1)*sizeof(char));*/
	for(i=0;i<2*n+1;i++)
		for(j=0;j<2*n+1;j++)
			{a[i][j]=' ';/*printf("%c",a[i][j]);*/}

	for(i=0;i<n;i++)
		for(j=n-i;j<=n+i;j++)
			{a[i][j]='*';/*printf("%c",a[i][j]);*/}

	for(i=n,j=0;j<2*n+1;j++) a[i][j]='*';

	for(i=n+1;i<2*n+1;i++)
		for(j=i-n;j<=2*n-(i-n);j++)
			{a[i][j]='*';/*printf("%c",a[i][j]);*/}
	
for(i=0;i<2*n+1;i++){
		for(j=0;j<2*n+1;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
}
return 0;
}
